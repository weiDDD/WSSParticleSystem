#include "lua_cocos2dx_TalkingDataGA_auto.hpp"
#include "TDCCTalkingDataGA.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



bool luaval_to_tdga_map(lua_State* L,int lo,EventParamMap* outValue)
{
    if (NULL == L || NULL == outValue)
        return false;
    
    bool ok = true;
    
    tolua_Error tolua_err;
    if (!tolua_istable(L,lo,0,&tolua_err))
    {
#if COCOS2D_DEBUG >=1
        luaval_to_native_err(L,"#ferror:",&tolua_err);
#endif
        ok = false;
    }
    
    if (ok) {
        lua_pushnil(L);
        while (lua_next(L, lo))
        {
            lua_pushvalue(L, -2);
            const char* key = lua_tostring(L, -1);
            const char* value = lua_tostring(L, -2);
            (*outValue).insert(EventParamPair(key, value));
            lua_pop(L, 2);
        }
    }
    
    return ok;
}
int lua_cocos2dx_TalkingDataGA_setVerboseLogEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        TDCCTalkingDataGA::setVerboseLogEnabled();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setVerboseLogEnabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_setVerboseLogEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_onKill(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        TDCCTalkingDataGA::onKill();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onKill",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_onKill'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_onStart(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        TDCCTalkingDataGA::onStart(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onStart",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_onStart'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_getDeviceId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        const char* ret = TDCCTalkingDataGA::getDeviceId();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "getDeviceId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_getDeviceId'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_onEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        TDCCTalkingDataGA::onEvent(arg0);
        return 0;
    }
    if (argc == 2)
    {
        const char* arg0;
        EventParamMap* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        EventParamMap arg1_tmp; ok &= luaval_to_tdga_map(tolua_S, 3, &arg1_tmp); arg1 = &arg1_tmp;
        if(!ok)
            return 0;
        TDCCTalkingDataGA::onEvent(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onEvent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_onEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_setVerboseLogDisabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
            return 0;
        TDCCTalkingDataGA::setVerboseLogDisabled();
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setVerboseLogDisabled",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_setVerboseLogDisabled'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TalkingDataGA_setLocation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TalkingDataGA",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        double arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        ok &= luaval_to_number(tolua_S, 3,&arg1);
        if(!ok)
            return 0;
        TDCCTalkingDataGA::setLatitude(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setLocation",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TalkingDataGA_setLocation'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TalkingDataGA_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TalkingDataGA)");
    return 0;
}

int lua_register_cocos2dx_TalkingDataGA(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TalkingDataGA");
    tolua_cclass(tolua_S,"TalkingDataGA","TalkingDataGA","",nullptr);

    tolua_beginmodule(tolua_S,"TalkingDataGA");
        tolua_function(tolua_S,"setVerboseLogEnabled", lua_cocos2dx_TalkingDataGA_setVerboseLogEnabled);
        tolua_function(tolua_S,"onKill", lua_cocos2dx_TalkingDataGA_onKill);
        tolua_function(tolua_S,"onStart", lua_cocos2dx_TalkingDataGA_onStart);
        tolua_function(tolua_S,"getDeviceId", lua_cocos2dx_TalkingDataGA_getDeviceId);
        tolua_function(tolua_S,"onEvent", lua_cocos2dx_TalkingDataGA_onEvent);
        tolua_function(tolua_S,"setVerboseLogDisabled", lua_cocos2dx_TalkingDataGA_setVerboseLogDisabled);
        tolua_function(tolua_S,"setLocation", lua_cocos2dx_TalkingDataGA_setLocation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCTalkingDataGA).name();
    g_luaType[typeName] = "TalkingDataGA";
    g_typeCast["TalkingDataGA"] = "TalkingDataGA";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TalkingDataGA(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TalkingDataGA(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

