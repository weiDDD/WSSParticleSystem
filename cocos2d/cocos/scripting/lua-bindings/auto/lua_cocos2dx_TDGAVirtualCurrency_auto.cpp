#include "lua_cocos2dx_TDGAVirtualCurrency_auto.hpp"
#include "TDCCVirtualCurrency.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_TDGAVirtualCurrency_onChargeRequest(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAVirtualCurrency",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 6)
    {
        const char* arg0;
        const char* arg1;
        double arg2;
        const char* arg3;
        double arg4;
        const char* arg5;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp); arg3 = arg3_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 6,&arg4);
        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp); arg5 = arg5_tmp.c_str();
        if(!ok)
            return 0;
        TDCCVirtualCurrency::onChargeRequest(arg0, arg1, arg2, arg3, arg4, arg5);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onChargeRequest",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAVirtualCurrency_onChargeRequest'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAVirtualCurrency_onReward(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAVirtualCurrency",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        double arg0;
        const char* arg1;
        ok &= luaval_to_number(tolua_S, 2,&arg0);
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp); arg1 = arg1_tmp.c_str();
        if(!ok)
            return 0;
        TDCCVirtualCurrency::onReward(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onReward",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAVirtualCurrency_onReward'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAVirtualCurrency_onChargeSuccess(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAVirtualCurrency",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        TDCCVirtualCurrency::onChargeSuccess(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onChargeSuccess",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAVirtualCurrency_onChargeSuccess'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TDGAVirtualCurrency_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TDGAVirtualCurrency)");
    return 0;
}

int lua_register_cocos2dx_TDGAVirtualCurrency(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TDGAVirtualCurrency");
    tolua_cclass(tolua_S,"TDGAVirtualCurrency","TDGAVirtualCurrency","",nullptr);

    tolua_beginmodule(tolua_S,"TDGAVirtualCurrency");
        tolua_function(tolua_S,"onChargeRequest", lua_cocos2dx_TDGAVirtualCurrency_onChargeRequest);
        tolua_function(tolua_S,"onReward", lua_cocos2dx_TDGAVirtualCurrency_onReward);
        tolua_function(tolua_S,"onChargeSuccess", lua_cocos2dx_TDGAVirtualCurrency_onChargeSuccess);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCVirtualCurrency).name();
    g_luaType[typeName] = "TDGAVirtualCurrency";
    g_typeCast["TDGAVirtualCurrency"] = "TDGAVirtualCurrency";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TDGAVirtualCurrency(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TDGAVirtualCurrency(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

