#include "lua_cocos2dx_TDGAItem_auto.hpp"
#include "TDCCItem.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_TDGAItem_onPurchase(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        int arg1;
        double arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        ok &= luaval_to_number(tolua_S, 4,&arg2);
        if(!ok)
            return 0;
        TDCCItem::onPurchase(arg0, arg1, arg2);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onPurchase",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAItem_onPurchase'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAItem_onUse(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAItem",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        int arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1);
        if(!ok)
            return 0;
        TDCCItem::onUse(arg0, arg1);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "onUse",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAItem_onUse'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TDGAItem_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TDGAItem)");
    return 0;
}

int lua_register_cocos2dx_TDGAItem(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TDGAItem");
    tolua_cclass(tolua_S,"TDGAItem","TDGAItem","",nullptr);

    tolua_beginmodule(tolua_S,"TDGAItem");
        tolua_function(tolua_S,"onPurchase", lua_cocos2dx_TDGAItem_onPurchase);
        tolua_function(tolua_S,"onUse", lua_cocos2dx_TDGAItem_onUse);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCItem).name();
    g_luaType[typeName] = "TDGAItem";
    g_typeCast["TDGAItem"] = "TDGAItem";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TDGAItem(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TDGAItem(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

