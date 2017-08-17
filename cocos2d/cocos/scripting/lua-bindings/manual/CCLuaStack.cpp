/****************************************************************************
 Copyright (c) 2011-2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "CCLuaStack.h"
#include "tolua_fix.h"
#include "external/xxtea/xxtea.h"
extern "C" {
#include "lua.h"
#include "tolua++.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "Cocos2dxLuaLoader.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "platform/ios/CCLuaObjcBridge.h"
// talking Data
#include "lua_cocos2dx_TalkingDataGA_auto.hpp"
#include "lua_cocos2dx_TDGAAccount_auto.hpp"
#include "lua_cocos2dx_TDGAItem_auto.hpp"
#include "lua_cocos2dx_TDGAMission_auto.hpp"
#include "lua_cocos2dx_TDGAVirtualCurrency_auto.hpp"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCLuaJavaBridge.h"
// talking Data
#include "lua_cocos2dx_TalkingDataGA_auto.hpp"
#include "lua_cocos2dx_TDGAAccount_auto.hpp"
#include "lua_cocos2dx_TDGAItem_auto.hpp"
#include "lua_cocos2dx_TDGAMission_auto.hpp"
#include "lua_cocos2dx_TDGAVirtualCurrency_auto.hpp"
#endif

#include "LuaOpengl.h"
#include "LuaScriptHandlerMgr.h"
#include "lua_cocos2dx_auto.hpp"
#include "lua_cocos2dx_manual.hpp"
#include "LuaBasicConversions.h"
#include "lua_cocos2dx_deprecated.h"
#include "lua_cocos2dx_physics_auto.hpp"
#include "lua_cocos2dx_physics_manual.hpp"
#include "lua_cocos2dx_experimental_auto.hpp"
#include "lua_cocos2dx_experimental_manual.hpp"
#include "cocos2d/lua_feather_manual.hpp"
//#include "lua_feather_manual.hpp"

// 自定义导出类（Modified by LongYuanxian！2015-08-31 15:33:24）
#include "lua_feather_auto.hpp"

#include "feather/CommonFunc.h"

//////////////////////////////////////////////////////////////////////////
// 栈调试信息

#if COCOS2D_DEBUG >= 1

#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#define POINT_FMT_STR "0x%016llx"
#else
#define POINT_FMT_STR "0x%08x"
#endif

typedef std::unordered_map<const void *, int> TablePointers;
std::string luaStackValueToString(lua_State * state, int idx, bool meta, bool recursion,const char * prefix, TablePointers &tablePointers);

bool g_luaDebugTabAddr = false;		// 是否显示表的地址

// 得到用户类型的描述
std::string toluaGetUserTypeString(lua_State * state, int idx, bool meta, bool recursion, const char * prefix, TablePointers &tablePointers)
{
	CC_ASSERT(lua_isuserdata(state, idx));
	int scount = lua_gettop(state);

	void * ud = lua_touserdata(state, idx);

	if (lua_getmetatable(state, idx))				// stack: mt
	{
		std::string ret;

		lua_pushvalue(state, -1);					// stack: mt mt

		// 名字
		lua_rawget(state, LUA_REGISTRYINDEX);		// stack: mt name
		const char * tn = lua_tostring(state, -1);
		std::string name = tn ? tn : "";
		lua_pop(state, 1);							// stack: mt

		if (!meta)
		{
			lua_pop(state, 1);

			CC_ASSERT(lua_gettop(state) == scount);
			return fmtstr("%s:" POINT_FMT_STR, name, ud);
		}

		// 递归取表的描述
		std::string sMeta = luaStackValueToString(state, -1, meta, recursion, prefix, tablePointers);

		lua_pop(state, 1);							// stack: -

		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("%s:" POINT_FMT_STR " mt=%s", name, ud, sMeta);
	}

	CC_ASSERT(lua_gettop(state) == scount);
	return fmtstr("ud:" POINT_FMT_STR, ud);
}

std::string luaStackValueToString(lua_State * state, int idx, bool meta, bool recursion, const char * prefix, TablePointers &tablePointers)
{
	if (std::abs(idx) > lua_gettop(state))
		return "<err!>";

	int scount = lua_gettop(state);

	// 将栈位置转换为正向索引
	if (idx < 0)
		idx = lua_gettop(state) + idx + 1;

	int type = lua_type(state, idx);
	switch (type)
	{
	case LUA_TNUMBER:
		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("%f", lua_tonumber(state, idx));
	case LUA_TSTRING:
		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("'%s'", lua_tostring(state, idx));
	case LUA_TFUNCTION:
		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("cfunc:" POINT_FMT_STR, lua_topointer(state, idx));
	case LUA_TUSERDATA:
		CC_ASSERT(lua_gettop(state) == scount);
		return toluaGetUserTypeString(state, idx, meta, recursion,"", tablePointers);
	case LUA_TLIGHTUSERDATA:
		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("void*:" POINT_FMT_STR, lua_topointer(state, idx));
	case LUA_TTABLE:
	{
		// 处理重复表
		const void * tbl = lua_topointer(state, idx);
		if (!recursion || tablePointers.find(tbl) != tablePointers.end())
		{
			tablePointers[tbl] = 1;
			CC_ASSERT(lua_gettop(state) == scount);
			return fmtstr("{<table:" POINT_FMT_STR ">}", tbl);
		}

		tablePointers[tbl] = 0;
		std::string ret = fmtstr("table:" POINT_FMT_STR "{", tbl);
		std::string pfxStr = prefix; pfxStr += "\t";

		if (meta && lua_getmetatable(state, idx))
		{
			ret.append("\n");
			ret.append(pfxStr);

			ret.append("mt=");
			ret.append(luaStackValueToString(state,idx+1,meta,recursion,pfxStr.c_str(),tablePointers));

			lua_pop(state, 1);
		}

		lua_pushnil(state);
		int i = 0;
		while (lua_next(state, idx))
		{
			if (i > 0)
				ret.append(",");

			ret.append("\n");
			ret.append(pfxStr);

			ret.append(luaStackValueToString(state, lua_gettop(state) - 1, meta, recursion, pfxStr.c_str(), tablePointers));
			ret.append("=");
			ret.append(luaStackValueToString(state, lua_gettop(state), meta, recursion, pfxStr.c_str(), tablePointers));


			lua_pop(state, 1);	// 弹出当前值
			++i;
		}

		ret.append("\n");
		ret.append(prefix);
		ret.append("}");

		CC_ASSERT(lua_gettop(state) == scount);
		return ret;
	}
	case LUA_TBOOLEAN:
		CC_ASSERT(lua_gettop(state) == scount);
		return fmtstr("bool:%d", lua_toboolean(state, idx));
	case LUA_TNIL:
		return "<nil>";
	default:
		return fmtstr("<type:%d>", type);
	}
}

lua_State * g_dbgL = nullptr;

const std::string & getLuaStackString(int idx /*= 0*/, bool meta /*= false*/, bool recursion /*= false*/)
{
	static std::string ret;
	ret.clear();

	if (!g_dbgL)
		return ret = "no lua_State!";

	int count = lua_gettop(g_dbgL);
	if (count < 1)
		return ret = "lua stack is empty!";

	std::unordered_map<const void *, int> tablePointers;

	if (idx)
	{
		ret = fmtstr("lua stack %d = %s", idx, luaStackValueToString(g_dbgL, idx, meta, recursion, "\t", tablePointers));
	}
	else
	{
		ret.append(fmtstr("[[%d values]]:", count));

		ret.append("\n");
		for (int i = count; i >= 1; --i)
		{
			ret.append(fmtstr("stack %d => ", i));
			ret.append(luaStackValueToString(g_dbgL, i, meta, recursion, "\t", tablePointers));
			ret.append("\n");
		}
	}

	// 替换表的标识符：重复的去掉 'table:' 前缀，不重复的清除标示
	if (!g_luaDebugTabAddr)
		for (auto it = tablePointers.begin(); it != tablePointers.end(); ++it)
			if (it->second)
				replaceString(ret, fmtstr("table:" POINT_FMT_STR, it->first), fmtstr(POINT_FMT_STR, it->first));
			else
				replaceString(ret, fmtstr("table:" POINT_FMT_STR, it->first), "");

	return ret;
}

void outLuaStack(int stackIndex, const char * flag)
{
	if (!g_dbgL)
	{
		CCLOG("lua state is null");
		return;
	}

	int scount = lua_gettop(g_dbgL);

	std::string strFlag = flag ? flag : "";

	// 是否打印 表地址
	g_luaDebugTabAddr = strFlag.find("a") != std::string::npos;

	debugOut(getLuaStackString(stackIndex, 
		strFlag.find("m") != std::string::npos, 
		strFlag.find("r") != std::string::npos
		).c_str());

	CC_ASSERT(lua_gettop(g_dbgL) == scount);

	// 打印 tolua_gc_event 地址
	//lua_getfield(g_dbgL, LUA_REGISTRYINDEX, "tolua_gc_event");
	//if (lua_isnil(g_dbgL, -1))
	//	debugOut("tolua_gc_event is nil");
	//else
	//	debugOut(fmtstr("tolua_gc_event:0x%08x", lua_tocfunction(g_dbgL, -1)).c_str());
	//lua_pop(g_dbgL, 1);

	//CC_ASSERT(lua_gettop(g_dbgL) == scount);
}

void outLuaExpr(const char * expr)
{
	CC_ASSERT(0);
}

#endif


//////////////////////////////////////////////////////////////////////////

namespace {
int lua_print(lua_State * luastate)
{
    int nargs = lua_gettop(luastate);

    std::string t;
    for (int i=1; i <= nargs; i++)
    {
        if (lua_istable(luastate, i))
            t += "table";
        else if (lua_isnone(luastate, i))
            t += "none";
        else if (lua_isnil(luastate, i))
            t += "nil";
        else if (lua_isboolean(luastate, i))
        {
            if (lua_toboolean(luastate, i) != 0)
                t += "true";
            else
                t += "false";
        }
        else if (lua_isfunction(luastate, i))
            t += "function";
        else if (lua_islightuserdata(luastate, i))
            t += "lightuserdata";
        else if (lua_isthread(luastate, i))
            t += "thread";
        else
        {
            const char * str = lua_tostring(luastate, i);
            if (str)
                t += lua_tostring(luastate, i);
            else
                t += lua_typename(luastate, lua_type(luastate, i));
        }
        if (i!=nargs)
            t += "\t";
    }
    CCLOG("[LUA-print] %s", t.c_str());

    return 0;
}
    
int lua_release_print(lua_State * L)
{
    int nargs = lua_gettop(L);
    
    std::string t;
    for (int i=1; i <= nargs; i++)
    {
        if (lua_istable(L, i))
            t += "table";
        else if (lua_isnone(L, i))
            t += "none";
        else if (lua_isnil(L, i))
            t += "nil";
        else if (lua_isboolean(L, i))
        {
            if (lua_toboolean(L, i) != 0)
                t += "true";
            else
                t += "false";
        }
        else if (lua_isfunction(L, i))
            t += "function";
        else if (lua_islightuserdata(L, i))
            t += "lightuserdata";
        else if (lua_isthread(L, i))
            t += "thread";
        else
        {
            const char * str = lua_tostring(L, i);
            if (str)
                t += lua_tostring(L, i);
            else
                t += lua_typename(L, lua_type(L, i));
        }
        if (i!=nargs)
            t += "\t";
    }
    log("[LUA-print] %s", t.c_str());
    
    return 0;
}
}

NS_CC_BEGIN

LuaStack::~LuaStack()
{
    if (nullptr != _state)
    {
        lua_close(_state);
    }
}

LuaStack *LuaStack::create(void)
{
    LuaStack *stack = new (std::nothrow) LuaStack();
    stack->init();
    stack->autorelease();
    return stack;
}

LuaStack *LuaStack::attach(lua_State *L)
{
    LuaStack *stack = new (std::nothrow) LuaStack();
    stack->initWithLuaState(L);
    stack->autorelease();
    return stack;
}



bool LuaStack::init(void)
{
    _state = lua_open();

#if COCOS2D_DEBUG >= 1
	g_dbgL = _state;
#endif

    luaL_openlibs(_state);
    toluafix_open(_state);

    // Register our version of the global "print" function
    const luaL_reg global_functions [] = {
        {"print", lua_print},
        {"release_print",lua_release_print},

        {nullptr, nullptr}
    };
    luaL_register(_state, "_G", global_functions);

    g_luaType.clear();
    register_all_cocos2dx(_state);
	register_all_feather(_state);				// 自定义的导出类 （Modified by LongYuanxian！2015-08-31 15:33:24）
    tolua_opengl_open(_state);
    register_all_cocos2dx_manual(_state);
	register_all_feather_manual(_state);		// 自定义到处类（手工导出）（Modified by LongYuanxian！2015-08-31
    register_all_cocos2dx_module_manual(_state);
    register_all_cocos2dx_math_manual(_state);
    register_all_cocos2dx_experimental(_state);
    register_all_cocos2dx_experimental_manual(_state);

    register_glnode_manual(_state);
#if CC_USE_PHYSICS
    register_all_cocos2dx_physics(_state);
    register_all_cocos2dx_physics_manual(_state);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    LuaObjcBridge::luaopen_luaoc(_state);
	// talking Data
	register_all_cocos2dx_TalkingDataGA(_state);
	register_all_cocos2dx_TDGAAccount(_state);
	register_all_cocos2dx_TDGAMission(_state);
	register_all_cocos2dx_TDGAVirtualCurrency(_state);
	register_all_cocos2dx_TDGAItem(_state);
#endif
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    LuaJavaBridge::luaopen_luaj(_state);
	// talking Data
	register_all_cocos2dx_TalkingDataGA(_state);
	register_all_cocos2dx_TDGAAccount(_state);
	register_all_cocos2dx_TDGAMission(_state);
	register_all_cocos2dx_TDGAVirtualCurrency(_state);
	register_all_cocos2dx_TDGAItem(_state);
	
#endif
    register_all_cocos2dx_deprecated(_state);
    register_all_cocos2dx_manual_deprecated(_state);
    
    tolua_script_handler_mgr_open(_state);

    // add cocos2dx loader
    addLuaLoader(cocos2dx_lua_loader);

    return true;
}

bool LuaStack::initWithLuaState(lua_State *L)
{
    _state = L;
    return true;
}

void LuaStack::addSearchPath(const char* path)
{
    lua_getglobal(_state, "package");                                  /* L: package */
    lua_getfield(_state, -1, "path");                /* get package.path, L: package path */
    const char* cur_path =  lua_tostring(_state, -1);
    lua_pushfstring(_state, "%s;%s/?.lua", cur_path, path);            /* L: package path newpath */
    lua_setfield(_state, -3, "path");          /* package.path = newpath, L: package path */
    lua_pop(_state, 2);                                                /* L: - */
}

void LuaStack::addLuaLoader(lua_CFunction func)
{
    if (!func) return;
    
    // stack content after the invoking of the function
    // get loader table
    lua_getglobal(_state, "package");                                  /* L: package */
    lua_getfield(_state, -1, "loaders");                               /* L: package, loaders */
    
    // insert loader into index 2
    lua_pushcfunction(_state, func);                                   /* L: package, loaders, func */
    for (int i = (int)(lua_objlen(_state, -2) + 1); i > 2; --i)
    {
        lua_rawgeti(_state, -2, i - 1);                                /* L: package, loaders, func, function */
        // we call lua_rawgeti, so the loader table now is at -3
        lua_rawseti(_state, -3, i);                                    /* L: package, loaders, func */
    }
    lua_rawseti(_state, -2, 2);                                        /* L: package, loaders */
    
    // set loaders into package
    lua_setfield(_state, -2, "loaders");                               /* L: package */
    
    lua_pop(_state, 1);
}


void LuaStack::removeScriptObjectByObject(Ref* pObj)
{
    toluafix_remove_ccobject_by_refid(_state, pObj->_luaID);
}

void LuaStack::removeScriptHandler(int nHandler)
{
    toluafix_remove_function_by_refid(_state, nHandler);
}

int LuaStack::executeString(const char *codes)
{
    luaL_loadstring(_state, codes);
    return executeFunction(0);
}

int LuaStack::executeScriptFile(const char* filename)
{
    CCAssert(filename, "CCLuaStack::executeScriptFile() - invalid filename");
    
    static const std::string BYTECODE_FILE_EXT    = ".luac";
    static const std::string NOT_BYTECODE_FILE_EXT = ".lua";
    
    std::string buf(filename);
    //
    // remove .lua or .luac
    //
    size_t pos = buf.rfind(BYTECODE_FILE_EXT);
    if (pos != std::string::npos)
    {
        buf = buf.substr(0, pos);
    }
    else
    {
        pos = buf.rfind(NOT_BYTECODE_FILE_EXT);
        if (pos == buf.length() - NOT_BYTECODE_FILE_EXT.length())
        {
            buf = buf.substr(0, pos);
        }
    }
    
    FileUtils *utils = FileUtils::getInstance();
    //
    // 1. check .lua suffix
    // 2. check .luac suffix
    //
    std::string tmpfilename = buf + NOT_BYTECODE_FILE_EXT;
    if (utils->isFileExist(tmpfilename))
    {
        buf = tmpfilename;
    }
    else
    {
        tmpfilename = buf + BYTECODE_FILE_EXT;
        if (utils->isFileExist(tmpfilename))
        {
            buf = tmpfilename;
        }
    }
    
	CCLOG("lua stack  get file path:%s", buf.c_str());
    std::string fullPath = utils->fullPathForFilename(buf);
	CCLOG("lua stack  fullpath:%s", fullPath.c_str());
    Data data = utils->getDataFromFile(fullPath);
    int rn = 0;
    if (!data.isNull())
    {
		CCLOG("lua stack get data succ");
        if (luaLoadBuffer(_state, (const char*)data.getBytes(), (int)data.getSize(), fullPath.c_str()) == 0)
        {
			CCLOG("lua stack exec function");
            rn = executeFunction(0);
        }
    }
	else
	{
		CCLOG("lua stack get data fail");
	}
    return rn;
}

int LuaStack::executeGlobalFunction(const char* functionName)
{
    lua_getglobal(_state, functionName);       /* query function by name, stack: function */
    if (!lua_isfunction(_state, -1))
    {
        CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", functionName);
        lua_pop(_state, 1);
        return 0;
    }
    return executeFunction(0);
}

void LuaStack::clean(void)
{
    lua_settop(_state, 0);
}

void LuaStack::pushInt(int intValue)
{
    lua_pushinteger(_state, intValue);
}

void LuaStack::pushFloat(float floatValue)
{
    lua_pushnumber(_state, floatValue);
}

void LuaStack::pushLong(long longValue)
{
    lua_pushnumber(_state, longValue);
}

void LuaStack::pushBoolean(bool boolValue)
{
    lua_pushboolean(_state, boolValue);
}

void LuaStack::pushString(const char* stringValue)
{
    lua_pushstring(_state, stringValue);
}

void LuaStack::pushString(const char* stringValue, int length)
{
    lua_pushlstring(_state, stringValue, length);
}

void LuaStack::pushNil(void)
{
    lua_pushnil(_state);
}

void LuaStack::pushObject(Ref* objectValue, const char* typeName)
{
    toluafix_pushusertype_ccobject(_state, objectValue->_ID, &objectValue->_luaID, objectValue, typeName);
}

void LuaStack::pushLuaValue(const LuaValue& value)
{
    const LuaValueType type = value.getType();
    if (type == LuaValueTypeInt)
    {
        return pushInt(value.intValue());
    }
    else if (type == LuaValueTypeFloat)
    {
        return pushFloat(value.floatValue());
    }
    else if (type == LuaValueTypeBoolean)
    {
        return pushBoolean(value.booleanValue());
    }
    else if (type == LuaValueTypeString)
    {
        return pushString(value.stringValue().c_str());
    }
    else if (type == LuaValueTypeDict)
    {
        pushLuaValueDict(value.dictValue());
    }
    else if (type == LuaValueTypeArray)
    {
        pushLuaValueArray(value.arrayValue());
    }
    else if (type == LuaValueTypeObject)
    {
        pushObject(value.ccobjectValue(), value.getObjectTypename().c_str());
    }
}

void LuaStack::pushLuaValueDict(const LuaValueDict& dict)
{
    lua_newtable(_state);                                              /* L: table */
    for (LuaValueDictIterator it = dict.begin(); it != dict.end(); ++it)
    {
        lua_pushstring(_state, it->first.c_str());                     /* L: table key */
        pushLuaValue(it->second);                                     /* L: table key value */
        lua_rawset(_state, -3);                     /* table.key = value, L: table */
    }
}

void LuaStack::pushLuaValueArray(const LuaValueArray& array)
{
    lua_newtable(_state);                                              /* L: table */
    int index = 1;
    for (LuaValueArrayIterator it = array.begin(); it != array.end(); ++it)
    {
        pushLuaValue(*it);                                            /* L: table value */
        lua_rawseti(_state, -2, index);          /* table[index] = value, L: table */
        ++index;
    }
}

bool LuaStack::pushFunctionByHandler(int nHandler)
{
    toluafix_get_function_by_refid(_state, nHandler);                  /* L: ... func */
    if (!lua_isfunction(_state, -1))
    {
        CCLOG("[LUA ERROR] function refid '%d' does not reference a Lua function", nHandler);
        lua_pop(_state, 1);
        return false;
    }
    return true;
}

int LuaStack::executeFunction(int numArgs)
{
    int functionIndex = -(numArgs + 1);
    if (!lua_isfunction(_state, functionIndex))
    {
        CCLOG("value at stack [%d] is not function", functionIndex);
        lua_pop(_state, numArgs + 1); // remove function and arguments
        return 0;
    }

    int traceback = 0;
    lua_getglobal(_state, "__G__TRACKBACK__");                         /* L: ... func arg1 arg2 ... G */
    if (!lua_isfunction(_state, -1))
    {
        lua_pop(_state, 1);                                            /* L: ... func arg1 arg2 ... */
    }
    else
    {
        lua_insert(_state, functionIndex - 1);                         /* L: ... G func arg1 arg2 ... */
        traceback = functionIndex - 1;
    }
    
    int error = 0;
    ++_callFromLua;
    error = lua_pcall(_state, numArgs, 1, traceback);                  /* L: ... [G] ret */
    --_callFromLua;
    if (error)
    {
        if (traceback == 0)
        {
            CCLOG("[LUA ERROR] %s", lua_tostring(_state, - 1));        /* L: ... error */
            lua_pop(_state, 1); // remove error message from stack
        }
        else                                                            /* L: ... G error */
        {
            lua_pop(_state, 2); // remove __G__TRACKBACK__ and error message from stack
        }
        return 0;
    }
    
    // get return value
    int ret = 0;
    if (lua_isnumber(_state, -1))
    {
        ret = (int)lua_tointeger(_state, -1);
    }
    else if (lua_isboolean(_state, -1))
    {
        ret = (int)lua_toboolean(_state, -1);
    }
    // remove return value from stack
    lua_pop(_state, 1);                                                /* L: ... [G] */
    
    if (traceback)
    {
        lua_pop(_state, 1); // remove __G__TRACKBACK__ from stack      /* L: ... */
    }
    
    return ret;
}

int LuaStack::executeFunctionByHandler(int nHandler, int numArgs)
{
    int ret = 0;
    if (pushFunctionByHandler(nHandler))                                /* L: ... arg1 arg2 ... func */
    {
        if (numArgs > 0)
        {
            lua_insert(_state, -(numArgs + 1));                        /* L: ... func arg1 arg2 ... */
        }
        ret = executeFunction(numArgs);
    }
    lua_settop(_state, 0);
    return ret;
}

bool LuaStack::handleAssert(const char *msg)
{
    if (_callFromLua == 0) return false;
    
    lua_pushfstring(_state, "ASSERT FAILED ON LUA EXECUTE: %s", msg ? msg : "unknown");
    lua_error(_state);
    return true;
}

int LuaStack::reallocateScriptHandler(int nHandler)
{
    LUA_FUNCTION  nNewHandle = -1;
    
    if (pushFunctionByHandler(nHandler))
    {
       nNewHandle = toluafix_ref_function(_state,lua_gettop(_state),0);
    }
/*
    toluafix_get_function_by_refid(_state,nNewHandle);
    if (!lua_isfunction(_state, -1))
    {
        CCLOG("Error!");
    }
    lua_settop(_state, 0);
*/
    return nNewHandle;

}

int LuaStack::executeFunctionReturnArray(int handler,int numArgs,int numResults,__Array& resultArray)
{
    int top = lua_gettop(_state);
    if (pushFunctionByHandler(handler))                 /* L: ... arg1 arg2 ... func */
    {
        if (numArgs > 0)
        {
            lua_insert(_state, -(numArgs + 1));         /* L: ... func arg1 arg2 ... */
        }
        int functionIndex = -(numArgs + 1);
        if (!lua_isfunction(_state, functionIndex))
        {
            CCLOG("value at stack [%d] is not function", functionIndex);
            lua_pop(_state, numArgs + 1); // remove function and arguments
            lua_settop(_state,top);
            return 0;
        }
        
        int traceback = 0;
        lua_getglobal(_state, "__G__TRACKBACK__");                         /* L: ... func arg1 arg2 ... G */
        if (!lua_isfunction(_state, -1))
        {
            lua_pop(_state, 1);                                            /* L: ... func arg1 arg2 ... */
        }
        else
        {
            lua_insert(_state, functionIndex - 1);                         /* L: ... G func arg1 arg2 ... */
            traceback = functionIndex - 1;
        }
        
        int error = 0;
        ++_callFromLua;
        error = lua_pcall(_state, numArgs, numResults, traceback);                  /* L: ... [G] ret1 ret2 ... retResults*/
        --_callFromLua;
        if (error)
        {
            if (traceback == 0)
            {
                CCLOG("[LUA ERROR] %s", lua_tostring(_state, - 1));        /* L: ... error */
                lua_pop(_state, 1); // remove error message from stack
            }
            else                                                            /* L: ... G error */
            {
                lua_pop(_state, 2); // remove __G__TRACKBACK__ and error message from stack
            }
            lua_settop(_state,top);
            return 0;
        }
        
        // get return value,don't pass LUA_MULTRET to numResults,
        if (numResults <= 0)
        {
            lua_settop(_state,top);
            return 0;
        }
        
        for (int i = 0 ; i < numResults; i++)
        {
            if (lua_type(_state, -1) == LUA_TBOOLEAN) {
                
                bool value = lua_toboolean(_state, -1);
                resultArray.addObject(Bool::create(value)) ;
                
            }else if (lua_type(_state, -1) == LUA_TNUMBER) {
                
                double value = lua_tonumber(_state, -1);
                resultArray.addObject(Double::create(value));
                
            }else if (lua_type(_state, -1) == LUA_TSTRING) {
                
                const char* value = lua_tostring(_state, -1);
                resultArray.addObject(String::create(value));
                
            }else{
                
                resultArray.addObject(static_cast<Ref*>(tolua_tousertype(_state, -1, nullptr)));
            }
            // remove return value from stack
            lua_pop(_state, 1);                                                /* L: ... [G] ret1 ret2 ... ret*/
        }
        /* L: ... [G]*/
        
        if (traceback)
        {
            lua_pop(_state, 1); // remove __G__TRACKBACK__ from stack      /* L: ... */
        }
    }
    lua_settop(_state,top);
    return 1;
}

int LuaStack::executeFunction(int handler, int numArgs, int numResults, const std::function<void(lua_State*,int)>& func)
{
    if (pushFunctionByHandler(handler))                 /* L: ... arg1 arg2 ... func */
    {
        if (numArgs > 0)
        {
            lua_insert(_state, -(numArgs + 1));                        /* L: ... func arg1 arg2 ... */
        }
        
        int functionIndex = -(numArgs + 1);
        
        if (!lua_isfunction(_state, functionIndex))
        {
            CCLOG("value at stack [%d] is not function", functionIndex);
            lua_pop(_state, numArgs + 1); // remove function and arguments
            return 0;
        }
        
        int traceCallback = 0;
        lua_getglobal(_state, "__G__TRACKBACK__");                        /* L: ... func arg1 arg2 ... G */
        if (!lua_isfunction(_state, -1))
        {
            lua_pop(_state, 1);                                           /* L: ... func arg1 arg2 ... */
        }
        else
        {
            lua_insert(_state, functionIndex - 1);                         /* L: ... G func arg1 arg2 ... */
            traceCallback = functionIndex - 1;
        }
        
        int error = 0;
        ++_callFromLua;
        error = lua_pcall(_state, numArgs, numResults, traceCallback);     /* L: ... [G] ret1 ret2 ... retResults*/
        --_callFromLua;
        
        if (error)
        {
            if (traceCallback == 0)
            {
                CCLOG("[LUA ERROR] %s", lua_tostring(_state, - 1));        /* L: ... error */
                lua_pop(_state, 1);                                        // remove error message from stack
            }
            else                                                           /* L: ... G error */
            {
                lua_pop(_state, 2);                                        // remove __G__TRACKBACK__ and error message from stack
            }
            return 0;
        }
        
        // get return value,don't pass LUA_MULTRET to numResults,
        do {
            
            if (numResults <= 0 || nullptr == func)
                break;
            
            func(_state, numResults);
            
        } while (0);
        
        if (traceCallback)
        {
            lua_pop(_state, 1);                                          // remove __G__TRACKBACK__ from stack      /* L: ... */
        }
    }
    
    return 1;
}

int LuaStack::reload(const char* moduleFileName)
{
    if (nullptr == moduleFileName || strlen(moduleFileName) == 0)
    {
        CCLOG("moudulFileName is null");
        return 1;
    }

    lua_getglobal(_state, "package");                         /* L: package */
    lua_getfield(_state, -1, "loaded");                       /* L: package loaded */
    lua_pushstring(_state, moduleFileName);
    lua_gettable(_state, -2);                                 /* L:package loaded module */
    if (!lua_isnil(_state, -1))
    {
        lua_pushstring(_state, moduleFileName);               /* L:package loaded module name */
        lua_pushnil(_state);                                  /* L:package loaded module name nil*/
        lua_settable(_state, -4);                             /* L:package loaded module */
    }
    lua_pop(_state, 3);
    
    std::string name = moduleFileName;
    std::string require = "require \'" + name + "\'";
    return executeString(require.c_str());
}

void LuaStack::setXXTEAKeyAndSign(const char *key, int keyLen, const char *sign, int signLen)
{
    cleanupXXTEAKeyAndSign();
    
    if (key && keyLen && sign && signLen)
    {
        _xxteaKey = (char*)malloc(keyLen);
        memcpy(_xxteaKey, key, keyLen);
        _xxteaKeyLen = keyLen;
        
        _xxteaSign = (char*)malloc(signLen);
        memcpy(_xxteaSign, sign, signLen);
        _xxteaSignLen = signLen;
        
        _xxteaEnabled = true;
    }
    else
    {
        _xxteaEnabled = false;
    }
}

void LuaStack::cleanupXXTEAKeyAndSign()
{
    if (_xxteaKey)
    {
        free(_xxteaKey);
        _xxteaKey = nullptr;
        _xxteaKeyLen = 0;
    }
    if (_xxteaSign)
    {
        free(_xxteaSign);
        _xxteaSign = nullptr;
        _xxteaSignLen = 0;
    }
}

int LuaStack::loadChunksFromZIP(const char *zipFilePath)
{
    pushString(zipFilePath);
    luaLoadChunksFromZIP(_state);
    int ret = lua_toboolean(_state, -1);
    lua_pop(_state, 1);
    return ret;
}

int LuaStack::luaLoadChunksFromZIP(lua_State *L)
{
    if (lua_gettop(L) < 1) {
        CCLOG("luaLoadChunksFromZIP() - invalid arguments");
        return 0;
    }
    
    const char *zipFilename = lua_tostring(L, -1);
    lua_settop(L, 0);
    FileUtils *utils = FileUtils::getInstance();
    std::string zipFilePath = utils->fullPathForFilename(zipFilename);
    
    LuaStack *stack = this;
    
    do {
        ssize_t size = 0;
        void *buffer = nullptr;
        unsigned char *zipFileData = utils->getFileData(zipFilePath.c_str(), "rb", &size);
        ZipFile *zip = nullptr;
        
        bool isXXTEA = stack && stack->_xxteaEnabled && zipFileData;
        for (int i = 0; isXXTEA && i < stack->_xxteaSignLen && i < size; ++i) {
            isXXTEA = zipFileData[i] == stack->_xxteaSign[i];
        }
        
        if (isXXTEA) { // decrypt XXTEA
            xxtea_long len = 0;
            buffer = xxtea_decrypt(zipFileData + stack->_xxteaSignLen,
                                   (xxtea_long)size - (xxtea_long)stack->_xxteaSignLen,
                                   (unsigned char*)stack->_xxteaKey,
                                   (xxtea_long)stack->_xxteaKeyLen,
                                   &len);
            free(zipFileData);
            zipFileData = nullptr;
            zip = ZipFile::createWithBuffer(buffer, len);
        } else {
            if (zipFileData) {
                zip = ZipFile::createWithBuffer(zipFileData, size);
            }
        }
        
        if (zip) {
            CCLOG("lua_loadChunksFromZIP() - load zip file: %s%s", zipFilePath.c_str(), isXXTEA ? "*" : "");
            lua_getglobal(L, "package");
            lua_getfield(L, -1, "preload");
            
            int count = 0;
            std::string filename = zip->getFirstFilename();
            while (filename.length()) {
                ssize_t bufferSize = 0;
                unsigned char *zbuffer = zip->getFileData(filename.c_str(), &bufferSize);
                if (bufferSize) {
                    // remove extension
                    std::size_t found = filename.rfind(".lua");
                    if (found != std::string::npos)
                    {
                        filename.erase(found);
                    }
                    // replace path seperator '/' '\' to '.'
                    for (int i=0; i<filename.size(); i++) {
                        if (filename[i] == '/' || filename[i] == '\\') {
                            filename[i] = '.';
                        }
                    }
                    CCLOG("[luaLoadChunksFromZIP] add %s to preload", filename.c_str());
                    if (stack->luaLoadBuffer(L, (char*)zbuffer, (int)bufferSize, filename.c_str()) == 0) {
                        lua_setfield(L, -2, filename.c_str());
                        ++count;
                    }
                    free(zbuffer);
                }
                filename = zip->getNextFilename();
            }
            CCLOG("lua_loadChunksFromZIP() - loaded chunks count: %d", count);
            lua_pop(L, 2);
            lua_pushboolean(L, 1);
            
            delete zip;
        } else {
            CCLOG("lua_loadChunksFromZIP() - not found or invalid zip file: %s", zipFilePath.c_str());
            lua_pushboolean(L, 0);
        }
        
        if (zipFileData) {
            free(zipFileData);
        }
        
        if (buffer) {
            free(buffer);
        }
    } while (0);
    
    return 1;
}

int LuaStack::luaLoadBuffer(lua_State *L, const char *chunk, int chunkSize, const char *chunkName)
{
    int r = 0;
    
    if (_xxteaEnabled && strncmp(chunk, _xxteaSign, _xxteaSignLen) == 0)
    {
        // decrypt XXTEA
        xxtea_long len = 0;
        unsigned char* result = xxtea_decrypt((unsigned char*)chunk + _xxteaSignLen,
                                              (xxtea_long)chunkSize - _xxteaSignLen,
                                              (unsigned char*)_xxteaKey,
                                              (xxtea_long)_xxteaKeyLen,
                                              &len);
        r = luaL_loadbuffer(L, (char*)result, len, chunkName);
        free(result);
    }
    else
    {
        r = luaL_loadbuffer(L, chunk, chunkSize, chunkName);
    }
    
#if defined(COCOS2D_DEBUG) && COCOS2D_DEBUG > 0
    if (r)
    {
        switch (r)
        {
            case LUA_ERRSYNTAX:
                CCLOG("[LUA ERROR] load \"%s\", error: syntax error during pre-compilation.", chunkName);
                break;
                
            case LUA_ERRMEM:
                CCLOG("[LUA ERROR] load \"%s\", error: memory allocation error.", chunkName);
                break;
                
            case LUA_ERRFILE:
                CCLOG("[LUA ERROR] load \"%s\", error: cannot open/read file.", chunkName);
                break;
                
            default:
                CCLOG("[LUA ERROR] load \"%s\", error: unknown.", chunkName);
        }
    }
#endif
    return r;
}

NS_CC_END
