#include "lua_cocos2dx_TDGAAccount_auto.hpp"
#include "TDCCAccount.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



static TDCCAccount* tdgaAccount;
int lua_cocos2dx_TDGAAccount_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        TDCCAccount::TDCCGender arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setGender(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setAccountName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setAccountName(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setAccountName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setAccountName'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setAge(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setAccountType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        TDCCAccount::TDCCAccountType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setAccountType(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setAccountType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setAccountType'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setGameServer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setGameServer(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setGameServer",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setGameServer'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setAccount(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp); arg0 = arg0_tmp.c_str();
        if(!ok)
            return 0;
        tdgaAccount = TDCCAccount::setAccount(arg0);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setAccount",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setAccount'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_TDGAAccount_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TDGAAccount",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0);
        if(!ok)
            return 0;
        if (tdgaAccount)
            tdgaAccount->setLevel(arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d\n ", "setLevel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_TDGAAccount_setLevel'.",&tolua_err);
#endif
    return 0;
}
static int lua_cocos2dx_TDGAAccount_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TDGAAccount)");
    return 0;
}

int lua_register_cocos2dx_TDGAAccount(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TDGAAccount");
    tolua_cclass(tolua_S,"TDGAAccount","TDGAAccount","",nullptr);
    
    tolua_beginmodule(tolua_S,"TDGAAccount");
        tolua_constant(tolua_S,"kAccountAnonymous", TDCCAccount::kAccountAnonymous);
        tolua_constant(tolua_S,"kAccountRegistered", TDCCAccount::kAccountRegistered);
        tolua_constant(tolua_S,"kAccountSinaWeibo", TDCCAccount::kAccountSianWeibo);
        tolua_constant(tolua_S,"kAccountQQ", TDCCAccount::kAccountQQ);
        tolua_constant(tolua_S,"kAccountTencentWeibo", TDCCAccount::kAccountTencentWeibo);
        tolua_constant(tolua_S,"kAccountND91", TDCCAccount::kAccountND91);
        tolua_constant(tolua_S,"kAccountType1", TDCCAccount::kAccountType1);
        tolua_constant(tolua_S,"kAccountType2", TDCCAccount::kAccountType2);
        tolua_constant(tolua_S,"kAccountType3", TDCCAccount::kAccountType3);
        tolua_constant(tolua_S,"kAccountType4", TDCCAccount::kAccountType4);
        tolua_constant(tolua_S,"kAccountType5", TDCCAccount::kAccountType5);
        tolua_constant(tolua_S,"kAccountType6", TDCCAccount::kAccountType6);
        tolua_constant(tolua_S,"kAccountType7", TDCCAccount::kAccountType7);
        tolua_constant(tolua_S,"kAccountType8", TDCCAccount::kAccountType8);
        tolua_constant(tolua_S,"kAccountType9", TDCCAccount::kAccountType9);
        tolua_constant(tolua_S,"kAccountType10", TDCCAccount::kAccountType10);
    
        tolua_constant(tolua_S,"kGenderUnknown", TDCCAccount::kGenderUnknown);
        tolua_constant(tolua_S,"kGenderMale", TDCCAccount::kGenderMale);
        tolua_constant(tolua_S,"kGenderFemale", TDCCAccount::kGenderFemale);
    
        tolua_function(tolua_S,"setGender", lua_cocos2dx_TDGAAccount_setGender);
        tolua_function(tolua_S,"setAccountName", lua_cocos2dx_TDGAAccount_setAccountName);
        tolua_function(tolua_S,"setAge", lua_cocos2dx_TDGAAccount_setAge);
        tolua_function(tolua_S,"setAccountType", lua_cocos2dx_TDGAAccount_setAccountType);
        tolua_function(tolua_S,"setGameServer", lua_cocos2dx_TDGAAccount_setGameServer);
        tolua_function(tolua_S,"setAccount", lua_cocos2dx_TDGAAccount_setAccount);
        tolua_function(tolua_S,"setLevel", lua_cocos2dx_TDGAAccount_setLevel);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TDCCAccount).name();
    g_luaType[typeName] = "TDGAAccount";
    g_typeCast["TDGAAccount"] = "TDGAAccount";
    return 1;
}
TOLUA_API int register_all_cocos2dx_TDGAAccount(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_cocos2dx_TDGAAccount(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

