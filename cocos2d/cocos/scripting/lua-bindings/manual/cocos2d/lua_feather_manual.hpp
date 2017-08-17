/********************************************************************
    创建时间：  2015-08-31   17:13:33
    文件名：    lua_feather_manual.hpp
    作者：      隆元线

    功能：      1. 手动导出的 feather 函数
                2.

    说明：      1. 全局函数无法自动导出，故在这里导出
                2.
                3.
*********************************************************************/

#ifndef COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_GENERATED_LUA_FEATHER_MANUAL_H
#define COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_GENERATED_LUA_FEATHER_MANUAL_H

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "cocos2d.h"
#include "LuaScriptHandlerMgr.h"
#include "LuaBasicConversions.h"

NS_CC_BEGIN
class MotionFilter;
class MotionFactory;
NS_CC_END

#if COCOS2D_DEBUG >=1
extern void luaval_to_native_err(lua_State* L,const char* msg,tolua_Error* err, const char* funcName);
#endif

int register_all_feather_manual(lua_State* tolua_S);

// 自定义类型的转化模板，例如：
// object_to_luaval_x(lua_State* L, const char* type, XxxType * ret) 
// bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, XxxType * ret)
// bool luaval_to_object_by_ptr(lua_State* L, int lo, const char* type, XxxType ** ret)

// c++ => lua
void pointvector_to_luaval(lua_State* L, const char* type, const std::vector<cocos2d::Point> &points);

// lua => c++
bool luaval_to_object_by_val( lua_State* L, int lo, const char* type, std::vector<cocos2d::Vec2> * ret );
bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, cocos2d::ValueMap * ret);
template <class T> bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, std::vector<T *> * ret);
bool luaval_to_object_by_ptr(lua_State* L, int lo, const char* type, void ** ret);


//////////////////////////////////////////////////////////////////////////
// 实现代码

template <class T>
bool luaval_to_object_by_val(lua_State* L, int lo, const char* type, std::vector<T *> * ret)
{
	if (nullptr == L || nullptr == ret)
		return false;

	tolua_Error tolua_err;
	bool ok = true;
	if (!tolua_istable(L, lo, 0, &tolua_err))
	{
#if COCOS2D_DEBUG >=1
		luaval_to_native_err(L, "#ferror:", &tolua_err, type);
#endif
		ok = false;
	}

	if (ok)
	{
		size_t len = lua_objlen(L, lo);
		for (size_t i = 0; i < len; i++)
		{
			lua_pushnumber(L, i + 1);
			lua_gettable(L, lo);
			if (lua_isnil(L, -1))
			{
				lua_pop(L, 1);
				continue;
			}

			T * value;
			if (!luaval_to_object(L, lo + 1, type, &value))
			{
				lua_pop(L, 1);
				continue;
			}

			ret->push_back(value);
			lua_pop(L, 1);
		}
	}

	return ok;

}


#endif // #ifndef COCOS2DX_SCRIPT_LUA_COCOS2DX_SUPPORT_GENERATED_LUA_FEATHER_MANUAL_H
