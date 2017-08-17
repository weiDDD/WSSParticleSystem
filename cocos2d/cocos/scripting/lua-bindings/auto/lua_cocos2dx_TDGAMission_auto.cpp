#include "lua_cocos2dx_TDGAMission_auto.hpp"
#include "TDCCMission.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_TDGAMission_onFailed(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAMission",0,&tolua_err)) goto tolua_lerror;
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
        TDCCMission::onFailed(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onFailed",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAMission_onFailed'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAMission_onBegin(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAMission",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        TDCCMission::onBegin(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onBegin",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAMission_onBegin'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAMission_onCompleted(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAMission",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        TDCCMission::onCompleted(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onCompleted",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAMission_onCompleted'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TDGAMission_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TDGAMission)");
    return 0;
}

int lua_register_cocos2dx_TDGAMission(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TDGAMission");
    tolua_cclass(tolua_S,"TDGAMission","TDGAMission","",nullptr);

    tolua_beginmodule(tolua_S,"TDGAMission");
        tolua_function(tolua_S,"onFailed", lua_cocos2dx_TDGAMission_onFailed);
        tolua_function(tolua_S,"onBegin", lua_cocos2dx_TDGAMission_onBegin);
        tolua_function(tolua_S,"onCompleted", lua_cocos2dx_TDGAMission_onCompleted);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCMission).name();
    g_luaType[typeName] = "TDGAMission";
    g_typeCast["TDGAMission"] = "TDGAMission";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TDGAMission(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TDGAMission(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

