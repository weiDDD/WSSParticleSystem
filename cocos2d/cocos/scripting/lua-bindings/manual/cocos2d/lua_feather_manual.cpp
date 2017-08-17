/********************************************************************
    创建时间：  2015-08-31   17:16:28
    文件名：    lua_feather_manual.cpp
    作者：      隆元线

    功能：      1. 手工注册的 lua 函数
                2. 自定义的 lua 对象转换特化版

    说明：      1.
                2.
                3.
*********************************************************************/

#include "lua_feather_manual.hpp"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"
#if defined(_MSC_VER) || defined(__MINGW32__)
#include <WS2tcpip.h>
#else
#include <sys/socket.h>
#endif

#include "CommonFunc.h"
#include "platform/CCCommon.h"

#include "platform/Log.h"

#include "feather/ResourceLoader.h"
#include "feather/NetFileDownloader.h"
#include "feather/SqliteWrapConnect.h"
#include "feather/SqliteWrapQuery.h"
//#include "feather/MotionFactory.h"
//#include "feather/Motion.h"
#include "feather/FeatherCommonToLua.h"
#include "feather/AsyncSocket.h"

//////////////////////////////////////////////////////////////////////////
// lua 对象转换特化版
//
// 说明：在这里定义（重载）转换函数的特化版；在工程 libcocos2d 的 feather/FeatherLuabinding.h 中定义需要转换的类型
// 
// 可重载的特化函数：
//		object_to_luaval_x(lua_State* L, const char* type, XxxType * ret) 
//		bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, XxxType * ret)
//		bool luaval_to_object_by_ptr(lua_State* L, int lo, const char* type, XxxType ** ret)

// 转换 ValueMap
bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, cocos2d::ValueMap * ret)
{
	return luaval_to_ccvaluemap(L, lo, ret, type);
}


bool luaval_to_object_by_ptr(lua_State* L, int lo, const char* type, void ** ret)
{
	if (nullptr == L || lua_gettop(L) < lo)
		return false;

	switch (lua_type(L, lo))
	{
	case LUA_TNUMBER:
		*ret = (void *)(int)lua_tonumber(L, lo);
		break;
	case LUA_TFUNCTION:
		*ret = (void *)lua_topointer(L, lo);
		break;
	case LUA_TUSERDATA:
		*ret = (void *)lua_touserdata(L, lo);
		break;
	case LUA_TLIGHTUSERDATA:
	case LUA_TTABLE:
		*ret = (void *)lua_topointer(L, lo);
		break;
	default:
		*ret = 0;
		break;
	}

	if (nullptr == *ret)
		LUA_PRECONDITION(ret, "Invalid void pointer!");

	return true;

}

void pointvector_to_luaval(lua_State* L, const char* type, const std::vector<cocos2d::Point> &points)
{
	lua_newtable(L);

	if (nullptr == L)
		return;

	int indexTable = 1;
	for (const auto& point : points)
	{
		lua_pushnumber(L, (lua_Number)indexTable);
		vec2_to_luaval(L, point);
		lua_rawset(L, -3);

		++indexTable;
	}
}

//////////////////////////////////////////////////////////////////////////
// 导出函数

static int lua_feather_log_string(lua_State* tolua_S)
{	// log_string(file,prefix,postfix,logstring)


#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isstring(tolua_S, 1, 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 3, 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 4, 0, &tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		std::string  file = tolua_tocppstring(tolua_S, 1, "");
		std::string  prefix = tolua_tocppstring(tolua_S, 2, "");
		std::string  postfix = tolua_tocppstring(tolua_S, 3, "");
		std::string  logstring = tolua_tocppstring(tolua_S, 4, "");
		cocos2d::log_string(file.c_str(), prefix.empty() ? nullptr: prefix.c_str(), 
			postfix.empty() ? nullptr: postfix.c_str(), 
			logstring.empty() ? nullptr : logstring.c_str());

		return 0;
	}
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_log_string'.", &tolua_err);
	return 0;
#endif
}


static int lua_feather_log(lua_State* tolua_S)
{	// log_string(file,prefix,postfix,logstring)


#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isnumber(tolua_S, 1, 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 2, 0, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		int  n1 = (int)tolua_tonumber(tolua_S, 1, 2);
		std::string  s2 = tolua_tocppstring(tolua_S, 2, "");
		Log::printLogByLua(n1, s2.c_str());

		return 0;
	}
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_log'.", &tolua_err);
	return 0;
#endif
}

unsigned int lua_binding_get_object_id(lua_State* tolua_S, int idx)
{
	lua_pushstring(tolua_S, "_object_id");
	lua_gettable(tolua_S, idx > 0 ? idx : idx - 1);
	unsigned int ret = 0;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isnumber(tolua_S, -1, 0, &tolua_err))
	{
		tolua_error(tolua_S, "#ferror in function 'lua_binding_get_object_id'.", &tolua_err);
	}
	else
#endif
	{
		ret = tolua_tonumber(tolua_S, -1, 0);
		lua_pop(tolua_S, 1);
	}

	return ret;
}

int lua_feather_ResourceLoader_connect(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::ResourceLoader* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.ResourceLoader", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_ResourceLoader_connect'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		const void * object_id = lua_topointer(tolua_S,2);
		std::function<void(const std::basic_string<char> &)> callback;
		
		if (nullptr == object_id)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_ResourceLoader_connect'", nullptr);
			return 0;
		}

		lua_pushvalue(tolua_S,3);	// 参数复制到栈顶，以便 luaL_ref 使用
		int ref_callback = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		callback = [ref_callback, tolua_S](const std::basic_string<char> &group)
		{
			lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_callback);	// get function
			lua_pushstring(tolua_S, group.c_str());
			lua_pcall(tolua_S, 1, 0, 0);
		};

		cobj->connect(object_id, callback, ref_callback);
		lua_settop(tolua_S, 1);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:connect", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_ResourceLoader_connect'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_NetFileDownloader_setProcessCallback(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::NetFileDownloader* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.NetFileDownloader", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::NetFileDownloader*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_NetFileDownloader_setProcessCallback'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		if (lua_isfunction(tolua_S, 2))
		{
			std::function<void(int percent, const std::string &name)> callback;

			lua_pushvalue(tolua_S, 2);	// 参数复制到栈顶，以便 luaL_ref 使用
			int ref_callback = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
			callback = [ref_callback, tolua_S](int percent, const std::string &name)
			{
				lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_callback);	// get function
				lua_pushnumber(tolua_S, (lua_Number)percent);
				lua_pushstring(tolua_S, name.c_str());
				lua_pcall(tolua_S, 2, 0, 0);
			};

			cobj->setProcessCallback(callback, ref_callback);
		}
		else
		{
			cobj->setProcessCallback(nullptr, 0);
		}

		lua_settop(tolua_S, 1);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.NetFileDownloader:setProcessCallback", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_NetFileDownloader_setProcessCallback'.", &tolua_err);
#endif

	return 0;
}

int lua_debug_remove_object(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::Ref* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.Ref", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::Ref*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_Motion_setEventCallback'", nullptr);
		return 0;
	}
#endif

	if (cobj->_luaID)
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptObjectByObject(cobj);
		cobj->_luaID = 0;
	}

	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_Motion_setEventCallback'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_ResourceLoader_disconnect(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::ResourceLoader* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.ResourceLoader", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_ResourceLoader_disconnect'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		const void * object_id = lua_topointer(tolua_S, 2);
		if (!object_id)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_ResourceLoader_disconnect'", nullptr);
			return 0;
		}
		cobj->disconnect(object_id);
		lua_settop(tolua_S, 1);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:disconnect", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_ResourceLoader_disconnect'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_SqliteWrapConnect_querySingleRow(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::SqliteWrapConnect* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.SqliteWrapConnect", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_querySingleRow'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::unordered_map<std::string, cocos2d::Value> arg0;
		const char* arg1;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.SqliteWrapConnect:querySingleRow");

		std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.SqliteWrapConnect:querySingleRow"); arg1 = arg1_tmp.c_str();
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_SqliteWrapConnect_querySingleRow'", nullptr);
			return 0;
		}
		bool ret = cobj->querySingleRow(arg0, arg1);

		// 更新传入的表
		ccvaluemap_to_luaval(tolua_S, 2, arg0);

		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:querySingleRow", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_SqliteWrapConnect_querySingleRow'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_SqliteWrapConnect_queryKeyValues(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::SqliteWrapConnect* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.SqliteWrapConnect", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_queryKeyValues'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		const char* arg0;
		std::unordered_map<std::string, cocos2d::Value> arg1;

		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:queryKeyValues"); arg0 = arg0_tmp.c_str();

		ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.SqliteWrapConnect:queryKeyValues");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_SqliteWrapConnect_queryKeyValues'", nullptr);
			return 0;
		}
		bool ret = cobj->queryKeyValues(arg0, arg1);

		// 更新传入的表
		ccvaluemap_to_luaval(tolua_S, 3, arg1);

		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:queryKeyValues", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_SqliteWrapConnect_queryKeyValues'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_SqliteWrapQuery_getRow(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::SqliteWrapQuery* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.SqliteWrapQuery", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::SqliteWrapQuery*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_SqliteWrapQuery_getRow'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		std::unordered_map<std::string, cocos2d::Value> arg0;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.SqliteWrapQuery:getRow");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_SqliteWrapQuery_getRow'", nullptr);
			return 0;
		}
		bool ret = cobj->getRow(arg0);

		// 更新传入的表
		ccvaluemap_to_luaval(tolua_S, 2, arg0);

		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapQuery:getRow", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_SqliteWrapQuery_getRow'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_SqliteWrapQuery_fetch(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::SqliteWrapQuery* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.SqliteWrapQuery", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::SqliteWrapQuery*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_SqliteWrapQuery_fetch'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_SqliteWrapQuery_fetch'", nullptr);
			return 0;
		}
		bool ret = cobj->fetch();

		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	if (argc == 1)
	{
		std::unordered_map<std::string, cocos2d::Value> arg0;

		ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.SqliteWrapQuery:fetch");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_SqliteWrapQuery_fetch'", nullptr);
			return 0;
		}
		bool ret = cobj->fetch(&arg0);

		// 更新传入的表
		ccvaluemap_to_luaval(tolua_S, 2, arg0);

		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapQuery:fetch", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_SqliteWrapQuery_fetch'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_SqliteWrapQuery_getField(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::SqliteWrapQuery* cobj = nullptr;
	bool ok = true;
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.SqliteWrapQuery", 0, &tolua_err)) goto tolua_lerror;
#endif
	cobj = (cocos2d::SqliteWrapQuery*)tolua_tousertype(tolua_S, 1, 0);
#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_SqliteWrapQuery_getField'", nullptr);
		return 0;
	}
#endif
	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) 
	{
		switch (lua_type(tolua_S, 2))
		{
			case LUA_TSTRING:
			{
				std::string arg0;
				ok &= luaval_to_std_string(tolua_S, 2, &arg0, "cc.SqliteWrapQuery:getField");

				if (!ok) { break; }
				cocos2d::Value ret = cobj->getField(arg0);
				ccvalue_to_luaval(tolua_S, ret);
				return 1;
			}
			
			case LUA_TNUMBER:
			{
				int arg0;
				ok &= luaval_to_int32(tolua_S, 2, (int *)&arg0, "cc.SqliteWrapQuery:getField");

				if (!ok) { break; }
				cocos2d::Value ret = cobj->getField(arg0);
				ccvalue_to_luaval(tolua_S, ret);
				return 1;
			}
			
			default:
				break;
		}
	}

	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapQuery:getField", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_SqliteWrapQuery_getField'.", &tolua_err);
#endif

	return 0;
}

int lua_feather_fc_unzipFileAsync(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "cc.fc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 4)
	{
		std::string arg0;
		std::string arg1;
		std::string arg2;
		std::function<void(fc::UnzipStep step, const std::string &fileName, int percent, const char * error)> callback;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "cc.fc:unzipFileAsync");
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, "cc.fc:unzipFileAsync");
		ok &= luaval_to_std_string(tolua_S, 4, &arg2, "cc.fc:unzipFileAsync");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_fc_unzipFileAsync'", nullptr);
			return 0;
		}

		lua_pushvalue(tolua_S, 5);	// 参数复制到栈顶，以便 luaL_ref 使用
		int ref_callback = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		callback = [ref_callback, tolua_S](fc::UnzipStep step, const std::string &fileName, int percent, const char * error)
		{
			lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_callback);	// get function
			
			lua_pushnumber(tolua_S, (int)step);
			lua_pushstring(tolua_S, fileName.c_str());
			lua_pushnumber(tolua_S, (int)percent);
			if (error && *error)
				lua_pushstring(tolua_S, error);
			else
				lua_pushnil(tolua_S);

			lua_pcall(tolua_S, 4, 0, 0);
		};

		const bool ret = cocos2d::fc::unzipFileAsync(arg0, arg1, arg2, callback);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:unzipFileAsync", argc, 4);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_fc_unzipFileAsync'.", &tolua_err);
#endif
	return 0;
}


int lua_feather_AsyncSocket_setEventCallback(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::AsyncSocket* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.AsyncSocket", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::AsyncSocket*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_AsyncSocket_setEventCallback'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::function<void(cocos2d::AsyncSocket::Event)> statusCb;
		lua_pushvalue(tolua_S, 2);	// 参数复制到栈顶，以便 luaL_ref 使用
		int ref_statusCb = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		statusCb = [ref_statusCb, tolua_S](cocos2d::AsyncSocket::Event evt)
		{
			lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_statusCb);	// get function
			lua_pushnumber(tolua_S, (lua_Number)evt.type);
			lua_pushstring(tolua_S, evt.msg.c_str());
			lua_pcall(tolua_S, 2, 0, 0);
		};

		std::function<void(cocos2d::AsyncSocket::Buf)> dataCb;
		lua_pushvalue(tolua_S, 3);	// 参数复制到栈顶，以便 luaL_ref 使用
		int ref_dataCb = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		dataCb = [ref_dataCb, tolua_S](cocos2d::AsyncSocket::Buf buf)
		{
			lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_dataCb);	// get function
			lua_pushlstring(tolua_S, buf.data,buf.len);
			lua_pcall(tolua_S, 1, 0, 0);
		};

		cobj->setEventCallback(statusCb, dataCb);
		lua_settop(tolua_S, 1);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AsyncSocket:setEventCallback", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_feather_AsyncSocket_setEventCallback'.", &tolua_err);
#endif

				return 0;
}


int lua_feather_AsyncSocket_sendData(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::AsyncSocket* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.AsyncSocket", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::AsyncSocket*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_AsyncSocket_sendData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		size_t sz = 0;
		const char * msg = luaL_checklstring(tolua_S, 2, &sz);
		if (sz < 1)
		{
			luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AsyncSocket:sendData", argc, 1);
			return 0;
		}
		
		cocos2d::AsyncSocket::Buf buf;
		buf.data = new char[sz];
		memcpy(buf.data, msg, sz);
		buf.len = (int)sz;
		cobj->sendData(buf);

		lua_settop(tolua_S, 1);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AsyncSocket:sendData", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_feather_AsyncSocket_sendData'.", &tolua_err);
#endif

				return 0;
}

int lua_feather_ZipFile_writeAllFileData(lua_State* tolua_S)
{
	int argc = 0;
	cocos2d::ZipFile* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "cc.ZipFile", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (cocos2d::ZipFile*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_feather_ZipFile_writeAllFileData'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 2)
	{
		std::string arg0;
		std::function<void(int, const std::string &)> callback;

		ok &= luaval_to_std_string(tolua_S, 2, &arg0, "cc.ZipFile:writeAllFileData");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_feather_ZipFile_writeAllFileData'", nullptr);
			return 0;
		}

		lua_pushvalue(tolua_S, 3);	// 参数复制到栈顶，以便 luaL_ref 使用
		int ref_callback = luaL_ref(tolua_S, LUA_REGISTRYINDEX);
		callback = [ref_callback, tolua_S](int percent,const std::string &msg)
		{
			// -2 为内部退出指令
			if (-2 == percent)
			{
				luaL_unref(tolua_S, LUA_REGISTRYINDEX, ref_callback);
			}
			else
			{
				lua_rawgeti(tolua_S, LUA_REGISTRYINDEX, ref_callback);	// get function

				lua_pushnumber(tolua_S, percent);
				lua_pushstring(tolua_S, msg.c_str());

				lua_pcall(tolua_S, 2, 0, 0);
			}
		};

		int ret = cobj->writeAllFileData(arg0, callback);
		lua_pushnumber(tolua_S, (int)ret);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ZipFile:writeAllFileData", argc, 2);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_feather_ZipFile_writeAllFileData'.", &tolua_err);
#endif

	return 0;
}

int register_all_feather_manual(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    
	// 全局函数
	tolua_module(tolua_S, NULL, 0);
	tolua_beginmodule(tolua_S, NULL);
	{
		tolua_function(tolua_S, "trace_string", lua_feather_log_string);
		tolua_function(tolua_S, "feather_log", lua_feather_log);

		tolua_function(tolua_S, "debug_remove_object", lua_debug_remove_object);
	}
	tolua_endmodule(tolua_S);

	// ResourceLoader 的 connect / disconnect
	lua_pushstring(tolua_S, "cc.ResourceLoader");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "connect", lua_feather_ResourceLoader_connect);
		tolua_function(tolua_S, "disconnect", lua_feather_ResourceLoader_disconnect);
	}
	lua_pop(tolua_S, 1);

	// NetFileDownloader 的 connect / disconnect
	lua_pushstring(tolua_S, "cc.NetFileDownloader");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "setProcessCallback", lua_feather_NetFileDownloader_setProcessCallback);
	}
	lua_pop(tolua_S, 1);

	// SqliteWrapQuery
	lua_pushstring(tolua_S, "cc.SqliteWrapQuery");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	if (lua_istable(tolua_S, -1))
	{
		tolua_function(tolua_S, "getRow", lua_feather_SqliteWrapQuery_getRow);
		tolua_function(tolua_S, "fetch", lua_feather_SqliteWrapQuery_fetch);
		tolua_function(tolua_S, "getField", lua_feather_SqliteWrapQuery_getField);
	}
	lua_pop(tolua_S, 1);

	// SqliteWrapConnect
	lua_pushstring(tolua_S, "cc.SqliteWrapConnect");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	{
		tolua_function(tolua_S, "querySingleRow", lua_feather_SqliteWrapConnect_querySingleRow);
		tolua_function(tolua_S, "queryKeyValues", lua_feather_SqliteWrapConnect_queryKeyValues);
	}
	lua_pop(tolua_S, 1);

	// fc
	lua_pushstring(tolua_S, "cc.fc");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	{
		tolua_function(tolua_S, "unzipFileAsync", lua_feather_fc_unzipFileAsync);
	}
	lua_pop(tolua_S, 1);

	// AsyncSocket
	lua_pushstring(tolua_S, "cc.AsyncSocket");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	{
		tolua_function(tolua_S, "setEventCallback", lua_feather_AsyncSocket_setEventCallback);
		tolua_function(tolua_S, "sendData", lua_feather_AsyncSocket_sendData);
	}
	lua_pop(tolua_S, 1);

	// ZipFile
	lua_pushstring(tolua_S, "cc.ZipFile");
	lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	{
		tolua_function(tolua_S, "writeAllFileData", lua_feather_ZipFile_writeAllFileData);
	}
	lua_pop(tolua_S, 1);

	//////// MotionFactory
	//////lua_pushstring(tolua_S, "cc.MotionFactory");
	//////lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	//////{
	//////	tolua_function(tolua_S, "setCreatorMotionCallback", lua_feather_MotionFactory_luaSetCreatorMotionCallback);
	//////}
	//////lua_pop(tolua_S, 1);

	//////// Motion
	//////lua_pushstring(tolua_S, "cc.Motion");
	//////lua_rawget(tolua_S, LUA_REGISTRYINDEX);
	//////{
	//////	tolua_function(tolua_S, "setEventCallback", lua_feather_Motion_setEventCallback);
	//////	tolua_function(tolua_S, "SetUpdateCallback", lua_feather_Motion_SetUpdateCallback);
	//////	tolua_function(tolua_S, "SetPreparePropCallback", lua_feather_Motion_SetPreparePropCallback);
	//////}
	//////lua_pop(tolua_S, 1);


	return 0;
}

bool luaval_to_object_by_val( lua_State* L, int lo, const char* type, std::vector<cocos2d::Vec2> * ret )
{
    if( nullptr == L || nullptr == ret )
        return false;

    tolua_Error tolua_err;
    bool ok = true;
    if( !tolua_istable( L, lo, 0, &tolua_err ) )
    {
#if COCOS2D_DEBUG >=1
        luaval_to_native_err( L, "#ferror:", &tolua_err, type );
#endif
        ok = false;
    }

    if( ok )
    {
        size_t len = lua_objlen( L, lo );
        for( size_t i = 0; i < len; i++ )
        {
            lua_pushnumber( L, i + 1 );
            lua_gettable( L, lo );
            if( lua_isnil( L, -1 ) )
            {
                lua_pop( L, 1 );
                continue;
            }

            cocos2d::Vec2 point;

            lua_getfield( L, -1, "x" );
            point.x = lua_tonumber( L, -1 );
            lua_pop( L, 1 );

            lua_getfield( L, -1, "y" );
            point.y = lua_tonumber( L, -1 );
            lua_pop( L, 1 );

            ret->push_back( point );

            lua_pop( L, 1 );
        }
    }

    return ok;
}