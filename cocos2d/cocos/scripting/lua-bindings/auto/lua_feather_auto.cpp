#include "lua_feather_auto.hpp"
#include "FeatherCommonToLua.h"
#include "ResourceLoader.h"
#include "SqliteWrapQuery.h"
#include "SqliteWrapConnect.h"
#include "ObjectPool.h"
#include "ObjectPool.h"
#include "TinyxmlDoc.h"
#include "TinyxmlAccessor.h"
#include "NetFileDownloader.h"
#include "AsyncSocket.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_feather_fc_ValueMapFormat(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::ValueMap arg0;
        const char* arg1;
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.fc:ValueMapFormat");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.fc:ValueMapFormat"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ValueMapFormat'", nullptr);
            return 0;
        }
        const std::string& ret = cocos2d::fc::ValueMapFormat(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::ValueMap arg0;
        const char* arg1;
        const char* arg2;
        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.fc:ValueMapFormat");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.fc:ValueMapFormat"); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "cc.fc:ValueMapFormat"); arg2 = arg2_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ValueMapFormat'", nullptr);
            return 0;
        }
        const std::string& ret = cocos2d::fc::ValueMapFormat(arg0, arg1, arg2);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:ValueMapFormat",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_ValueMapFormat'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_ProfilingEndTimingBlock(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.fc:ProfilingEndTimingBlock"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ProfilingEndTimingBlock'", nullptr);
            return 0;
        }
        cocos2d::fc::ProfilingEndTimingBlock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:ProfilingEndTimingBlock",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_ProfilingEndTimingBlock'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_pathUnicode2utf8(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.fc:pathUnicode2utf8");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_pathUnicode2utf8'", nullptr);
            return 0;
        }
        std::string ret = cocos2d::fc::pathUnicode2utf8(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:pathUnicode2utf8",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_pathUnicode2utf8'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_pathUtf82unicode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.fc:pathUtf82unicode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_pathUtf82unicode'", nullptr);
            return 0;
        }
        std::string ret = cocos2d::fc::pathUtf82unicode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:pathUtf82unicode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_pathUtf82unicode'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_getGlobalTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_getGlobalTime'", nullptr);
            return 0;
        }
        double ret = cocos2d::fc::getGlobalTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:getGlobalTime",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_getGlobalTime'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_ProfilingBeginTimingBlock(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.fc:ProfilingBeginTimingBlock"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ProfilingBeginTimingBlock'", nullptr);
            return 0;
        }
        cocos2d::fc::ProfilingBeginTimingBlock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:ProfilingBeginTimingBlock",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_ProfilingBeginTimingBlock'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_ProfilingDisplayTimers(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ProfilingDisplayTimers'", nullptr);
            return 0;
        }
        cocos2d::fc::ProfilingDisplayTimers();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:ProfilingDisplayTimers",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_ProfilingDisplayTimers'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_dockNodeInDevice(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Node* arg0;
        unsigned int arg1;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.fc:dockNodeInDevice");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_dockNodeInDevice'", nullptr);
            return 0;
        }
        cocos2d::fc::dockNodeInDevice(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3)
    {
        cocos2d::Node* arg0;
        unsigned int arg1;
        bool arg2;
        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "cc.fc:dockNodeInDevice");
        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "cc.fc:dockNodeInDevice");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_dockNodeInDevice'", nullptr);
            return 0;
        }
        cocos2d::fc::dockNodeInDevice(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:dockNodeInDevice",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_dockNodeInDevice'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_fc_ProfilingResetTimingBlock(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.fc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.fc:ProfilingResetTimingBlock"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_fc_ProfilingResetTimingBlock'", nullptr);
            return 0;
        }
        cocos2d::fc::ProfilingResetTimingBlock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.fc:ProfilingResetTimingBlock",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_fc_ProfilingResetTimingBlock'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_fc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (fc)");
    return 0;
}

int lua_register_feather_fc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.fc");
    tolua_cclass(tolua_S,"fc","cc.fc","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"fc");
        tolua_function(tolua_S,"ValueMapFormat", lua_feather_fc_ValueMapFormat);
        tolua_function(tolua_S,"ProfilingEndTimingBlock", lua_feather_fc_ProfilingEndTimingBlock);
        tolua_function(tolua_S,"pathUnicode2utf8", lua_feather_fc_pathUnicode2utf8);
        tolua_function(tolua_S,"pathUtf82unicode", lua_feather_fc_pathUtf82unicode);
        tolua_function(tolua_S,"getGlobalTime", lua_feather_fc_getGlobalTime);
        tolua_function(tolua_S,"ProfilingBeginTimingBlock", lua_feather_fc_ProfilingBeginTimingBlock);
        tolua_function(tolua_S,"ProfilingDisplayTimers", lua_feather_fc_ProfilingDisplayTimers);
        tolua_function(tolua_S,"dockNodeInDevice", lua_feather_fc_dockNodeInDevice);
        tolua_function(tolua_S,"ProfilingResetTimingBlock", lua_feather_fc_ProfilingResetTimingBlock);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::fc).name();
    g_luaType[typeName] = "cc.fc";
    g_typeCast["fc"] = "cc.fc";
    return 1;
}

int lua_feather_ResourceLoader_isMultiGroupLoaded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_isMultiGroupLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<std::string> arg0;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "cc.ResourceLoader:isMultiGroupLoaded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_isMultiGroupLoaded'", nullptr);
            return 0;
        }
        bool ret = cobj->isMultiGroupLoaded(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:isMultiGroupLoaded",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_isMultiGroupLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_isGroupLoaded(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_isGroupLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.ResourceLoader:isGroupLoaded");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_isGroupLoaded'", nullptr);
            return 0;
        }
        bool ret = cobj->isGroupLoaded(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:isGroupLoaded",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_isGroupLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_addGroup(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_addGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::vector<std::string> arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.ResourceLoader:addGroup");

        ok &= luaval_to_std_vector_string(tolua_S, 3, &arg1, "cc.ResourceLoader:addGroup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_addGroup'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->addGroup(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:addGroup",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_addGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getMultiGroupFileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getMultiGroupFileSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<std::string> arg0;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "cc.ResourceLoader:getMultiGroupFileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getMultiGroupFileSize'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getMultiGroupFileSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getMultiGroupFileSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getMultiGroupFileSize'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getGroupFileLoadedSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getGroupFileLoadedSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.ResourceLoader:getGroupFileLoadedSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getGroupFileLoadedSize'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getGroupFileLoadedSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getGroupFileLoadedSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getGroupFileLoadedSize'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getGroupLoadedPercent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getGroupLoadedPercent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getGroupLoadedPercent'", nullptr);
            return 0;
        }
        double ret = cobj->getGroupLoadedPercent();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.ResourceLoader:getGroupLoadedPercent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getGroupLoadedPercent'", nullptr);
            return 0;
        }
        double ret = cobj->getGroupLoadedPercent(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getGroupLoadedPercent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getGroupLoadedPercent'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getMultiGroupFileLoadedSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getMultiGroupFileLoadedSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<std::string> arg0;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "cc.ResourceLoader:getMultiGroupFileLoadedSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getMultiGroupFileLoadedSize'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getMultiGroupFileLoadedSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getMultiGroupFileLoadedSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getMultiGroupFileLoadedSize'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getLoadingGroup(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getLoadingGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getLoadingGroup'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getLoadingGroup();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getLoadingGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getLoadingGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getMultiGroupLoadedPercent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getMultiGroupLoadedPercent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<std::string> arg0;

        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "cc.ResourceLoader:getMultiGroupLoadedPercent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getMultiGroupLoadedPercent'", nullptr);
            return 0;
        }
        double ret = cobj->getMultiGroupLoadedPercent(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getMultiGroupLoadedPercent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getMultiGroupLoadedPercent'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_getGroupFileSize(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ResourceLoader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ResourceLoader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ResourceLoader_getGroupFileSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.ResourceLoader:getGroupFileSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getGroupFileSize'", nullptr);
            return 0;
        }
        ssize_t ret = cobj->getGroupFileSize(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ResourceLoader:getGroupFileSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getGroupFileSize'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ResourceLoader_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_destroyInstance'", nullptr);
            return 0;
        }
        cocos2d::ResourceLoader::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ResourceLoader:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_ResourceLoader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ResourceLoader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ResourceLoader_getInstance'", nullptr);
            return 0;
        }
        cocos2d::ResourceLoader* ret = cocos2d::ResourceLoader::getInstance();
        object_to_luaval<cocos2d::ResourceLoader>(tolua_S, "cc.ResourceLoader",(cocos2d::ResourceLoader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ResourceLoader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ResourceLoader_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_ResourceLoader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResourceLoader)");
    return 0;
}

int lua_register_feather_ResourceLoader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.ResourceLoader");
    tolua_cclass(tolua_S,"ResourceLoader","cc.ResourceLoader","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"ResourceLoader");
        tolua_function(tolua_S,"isMultiGroupLoaded",lua_feather_ResourceLoader_isMultiGroupLoaded);
        tolua_function(tolua_S,"isGroupLoaded",lua_feather_ResourceLoader_isGroupLoaded);
        tolua_function(tolua_S,"addGroup",lua_feather_ResourceLoader_addGroup);
        tolua_function(tolua_S,"getMultiGroupFileSize",lua_feather_ResourceLoader_getMultiGroupFileSize);
        tolua_function(tolua_S,"getGroupFileLoadedSize",lua_feather_ResourceLoader_getGroupFileLoadedSize);
        tolua_function(tolua_S,"getGroupLoadedPercent",lua_feather_ResourceLoader_getGroupLoadedPercent);
        tolua_function(tolua_S,"getMultiGroupFileLoadedSize",lua_feather_ResourceLoader_getMultiGroupFileLoadedSize);
        tolua_function(tolua_S,"getLoadingGroup",lua_feather_ResourceLoader_getLoadingGroup);
        tolua_function(tolua_S,"getMultiGroupLoadedPercent",lua_feather_ResourceLoader_getMultiGroupLoadedPercent);
        tolua_function(tolua_S,"getGroupFileSize",lua_feather_ResourceLoader_getGroupFileSize);
        tolua_function(tolua_S,"destroyInstance", lua_feather_ResourceLoader_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_feather_ResourceLoader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::ResourceLoader).name();
    g_luaType[typeName] = "cc.ResourceLoader";
    g_typeCast["ResourceLoader"] = "cc.ResourceLoader";
    return 1;
}

int lua_feather_SqliteWrapQuery_fetchError(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapQuery* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapQuery",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapQuery*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapQuery_fetchError'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapQuery_fetchError'", nullptr);
            return 0;
        }
        bool ret = cobj->fetchError();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapQuery:fetchError",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapQuery_fetchError'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapQuery_getFieldCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapQuery* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapQuery",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapQuery*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapQuery_getFieldCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapQuery_getFieldCount'", nullptr);
            return 0;
        }
        int ret = cobj->getFieldCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapQuery:getFieldCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapQuery_getFieldCount'.",&tolua_err);
#endif

    return 0;
}
static int lua_feather_SqliteWrapQuery_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SqliteWrapQuery)");
    return 0;
}

int lua_register_feather_SqliteWrapQuery(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.SqliteWrapQuery");
    tolua_cclass(tolua_S,"SqliteWrapQuery","cc.SqliteWrapQuery","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SqliteWrapQuery");
        tolua_function(tolua_S,"fetchError",lua_feather_SqliteWrapQuery_fetchError);
        tolua_function(tolua_S,"getFieldCount",lua_feather_SqliteWrapQuery_getFieldCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SqliteWrapQuery).name();
    g_luaType[typeName] = "cc.SqliteWrapQuery";
    g_typeCast["SqliteWrapQuery"] = "cc.SqliteWrapQuery";
    return 1;
}

int lua_feather_SqliteWrapConnect_begin(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_begin'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_begin'", nullptr);
            return 0;
        }
        cobj->begin();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:begin",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_begin'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_tableExists(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_tableExists'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:tableExists"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_tableExists'", nullptr);
            return 0;
        }
        bool ret = cobj->tableExists(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:tableExists",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_tableExists'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_initWithDbFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_initWithDbFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.SqliteWrapConnect:initWithDbFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_initWithDbFile'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithDbFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:initWithDbFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_initWithDbFile'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_exec(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_exec'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:exec"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.SqliteWrapConnect:exec");

            if (!ok) { break; }
            bool ret = cobj->exec(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:exec"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->exec(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.SqliteWrapConnect:exec",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_exec'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_lastInsertRowid(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_lastInsertRowid'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_lastInsertRowid'", nullptr);
            return 0;
        }
        long long ret = cobj->lastInsertRowid();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:lastInsertRowid",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_lastInsertRowid'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_isRowExist(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_isRowExist'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:isRowExist"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.SqliteWrapConnect:isRowExist");

            if (!ok) { break; }
            bool ret = cobj->isRowExist(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:isRowExist"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            bool ret = cobj->isRowExist(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.SqliteWrapConnect:isRowExist",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_isRowExist'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_insertRow(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_insertRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::ValueMap arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:insertRow"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::ValueMap>(tolua_S, 3, "std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_insertRow'", nullptr);
            return 0;
        }
        bool ret = cobj->insertRow(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:insertRow",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_insertRow'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_query(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_query'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:query"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "cc.SqliteWrapConnect:query");

            if (!ok) { break; }
            cocos2d::SqliteWrapQuery* ret = cobj->query(arg0, arg1);
            object_to_luaval<cocos2d::SqliteWrapQuery>(tolua_S, "cc.SqliteWrapQuery",(cocos2d::SqliteWrapQuery*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:query"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::SqliteWrapQuery* ret = cobj->query(arg0);
            object_to_luaval<cocos2d::SqliteWrapQuery>(tolua_S, "cc.SqliteWrapQuery",(cocos2d::SqliteWrapQuery*)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.SqliteWrapConnect:query",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_query'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_commit(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_commit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_commit'", nullptr);
            return 0;
        }
        cobj->commit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:commit",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_commit'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_close(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_close'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_close'", nullptr);
            return 0;
        }
        cobj->close();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:close",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_close'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_writeKeyValues(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_writeKeyValues'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        cocos2d::ValueMap arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:writeKeyValues"); arg0 = arg0_tmp.c_str();

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.SqliteWrapConnect:writeKeyValues"); arg1 = arg1_tmp.c_str();

        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "cc.SqliteWrapConnect:writeKeyValues"); arg2 = arg2_tmp.c_str();

        ok &= luaval_to_object<cocos2d::ValueMap>(tolua_S, 5, "std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >",&arg3);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_writeKeyValues'", nullptr);
            return 0;
        }
        bool ret = cobj->writeKeyValues(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:writeKeyValues",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_writeKeyValues'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_querySingleValue(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_querySingleValue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::ValueMap arg0;
            ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "cc.SqliteWrapConnect:querySingleValue");

            if (!ok) { break; }
            const char* arg1;
            std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "cc.SqliteWrapConnect:querySingleValue"); arg1 = arg1_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Value ret = cobj->querySingleValue(arg0, arg1);
            ccvalue_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:querySingleValue"); arg0 = arg0_tmp.c_str();

            if (!ok) { break; }
            cocos2d::Value ret = cobj->querySingleValue(arg0);
            ccvalue_to_luaval(tolua_S, ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.SqliteWrapConnect:querySingleValue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_querySingleValue'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_updateRow(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_updateRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::ValueMap arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.SqliteWrapConnect:updateRow"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::ValueMap>(tolua_S, 3, "std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_updateRow'", nullptr);
            return 0;
        }
        bool ret = cobj->updateRow(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:updateRow",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_updateRow'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_getDb(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SqliteWrapConnect* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SqliteWrapConnect*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_SqliteWrapConnect_getDb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_getDb'", nullptr);
            return 0;
        }
        sqlite3* ret = cobj->getDb();
        #pragma warning NO CONVERSION FROM NATIVE FOR sqlite3*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SqliteWrapConnect:getDb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_getDb'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_SqliteWrapConnect_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.SqliteWrapConnect",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_SqliteWrapConnect_create'", nullptr);
            return 0;
        }
        cocos2d::SqliteWrapConnect* ret = cocos2d::SqliteWrapConnect::create();
        object_to_luaval<cocos2d::SqliteWrapConnect>(tolua_S, "cc.SqliteWrapConnect",(cocos2d::SqliteWrapConnect*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.SqliteWrapConnect:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_SqliteWrapConnect_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_SqliteWrapConnect_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SqliteWrapConnect)");
    return 0;
}

int lua_register_feather_SqliteWrapConnect(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.SqliteWrapConnect");
    tolua_cclass(tolua_S,"SqliteWrapConnect","cc.SqliteWrapConnect","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"SqliteWrapConnect");
        tolua_function(tolua_S,"begin",lua_feather_SqliteWrapConnect_begin);
        tolua_function(tolua_S,"tableExists",lua_feather_SqliteWrapConnect_tableExists);
        tolua_function(tolua_S,"initWithDbFile",lua_feather_SqliteWrapConnect_initWithDbFile);
        tolua_function(tolua_S,"exec",lua_feather_SqliteWrapConnect_exec);
        tolua_function(tolua_S,"lastInsertRowid",lua_feather_SqliteWrapConnect_lastInsertRowid);
        tolua_function(tolua_S,"isRowExist",lua_feather_SqliteWrapConnect_isRowExist);
        tolua_function(tolua_S,"insertRow",lua_feather_SqliteWrapConnect_insertRow);
        tolua_function(tolua_S,"query",lua_feather_SqliteWrapConnect_query);
        tolua_function(tolua_S,"commit",lua_feather_SqliteWrapConnect_commit);
        tolua_function(tolua_S,"close",lua_feather_SqliteWrapConnect_close);
        tolua_function(tolua_S,"writeKeyValues",lua_feather_SqliteWrapConnect_writeKeyValues);
        tolua_function(tolua_S,"querySingleValue",lua_feather_SqliteWrapConnect_querySingleValue);
        tolua_function(tolua_S,"updateRow",lua_feather_SqliteWrapConnect_updateRow);
        tolua_function(tolua_S,"getDb",lua_feather_SqliteWrapConnect_getDb);
        tolua_function(tolua_S,"create", lua_feather_SqliteWrapConnect_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SqliteWrapConnect).name();
    g_luaType[typeName] = "cc.SqliteWrapConnect";
    g_typeCast["SqliteWrapConnect"] = "cc.SqliteWrapConnect";
    return 1;
}

int lua_feather_ObjectPool_reset(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ObjectPool_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ObjectPool:reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ObjectPool_resetByName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ObjectPool_resetByName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ObjectPool:resetByName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_resetByName'", nullptr);
            return 0;
        }
        cobj->resetByName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ObjectPool:resetByName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_resetByName'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ObjectPool_pushObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ObjectPool_pushObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Ref* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ObjectPool:pushObject"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_object<cocos2d::Ref>(tolua_S, 3, "cc.Ref",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_pushObject'", nullptr);
            return 0;
        }
        cobj->pushObject(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ObjectPool:pushObject",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_pushObject'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ObjectPool_popObject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::ObjectPool*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_ObjectPool_popObject'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.ObjectPool:popObject"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_popObject'", nullptr);
            return 0;
        }
        cocos2d::Ref* ret = cobj->popObject(arg0);
        object_to_luaval<cocos2d::Ref>(tolua_S, "cc.Ref",(cocos2d::Ref*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ObjectPool:popObject",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_popObject'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_ObjectPool_destroyObject(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_destroyObject'", nullptr);
            return 0;
        }
        cocos2d::ObjectPool::destroyObject();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ObjectPool:destroyObject",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_destroyObject'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_ObjectPool_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.ObjectPool",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_getInstance'", nullptr);
            return 0;
        }
        cocos2d::ObjectPool* ret = cocos2d::ObjectPool::getInstance();
        object_to_luaval<cocos2d::ObjectPool>(tolua_S, "cc.ObjectPool",(cocos2d::ObjectPool*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.ObjectPool:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_ObjectPool_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::ObjectPool* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_ObjectPool_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::ObjectPool();
        tolua_pushusertype(tolua_S,(void*)cobj,"cc.ObjectPool");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.ObjectPool:ObjectPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_feather_ObjectPool_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_feather_ObjectPool_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ObjectPool)");
    return 0;
}

int lua_register_feather_ObjectPool(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.ObjectPool");
    tolua_cclass(tolua_S,"ObjectPool","cc.ObjectPool","",nullptr);

    tolua_beginmodule(tolua_S,"ObjectPool");
        tolua_function(tolua_S,"new",lua_feather_ObjectPool_constructor);
        tolua_function(tolua_S,"reset",lua_feather_ObjectPool_reset);
        tolua_function(tolua_S,"resetByName",lua_feather_ObjectPool_resetByName);
        tolua_function(tolua_S,"pushObject",lua_feather_ObjectPool_pushObject);
        tolua_function(tolua_S,"popObject",lua_feather_ObjectPool_popObject);
        tolua_function(tolua_S,"destroyObject", lua_feather_ObjectPool_destroyObject);
        tolua_function(tolua_S,"getInstance", lua_feather_ObjectPool_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::ObjectPool).name();
    g_luaType[typeName] = "cc.ObjectPool";
    g_typeCast["ObjectPool"] = "cc.ObjectPool";
    return 1;
}

int lua_feather_TinyxmlAccessor_childrenWalker(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_childrenWalker'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_childrenWalker'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlAccessor* ret = cobj->childrenWalker();
        object_to_luaval<cocos2d::TinyxmlAccessor>(tolua_S, "cc.TinyxmlAccessor",(cocos2d::TinyxmlAccessor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:childrenWalker",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_childrenWalker'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_prev(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_prev'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_prev'", nullptr);
            return 0;
        }
        bool ret = cobj->prev();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:prev",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_prev'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_getProperty(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_getProperty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "cc.TinyxmlAccessor:getProperty"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_getProperty'", nullptr);
            return 0;
        }
        const char* ret = cobj->getProperty(arg0);
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:getProperty",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_getProperty'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_getParent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_getParent'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlAccessor* ret = cobj->getParent();
        object_to_luaval<cocos2d::TinyxmlAccessor>(tolua_S, "cc.TinyxmlAccessor",(cocos2d::TinyxmlAccessor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_getParent'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_getName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_getName'", nullptr);
            return 0;
        }
        const char* ret = cobj->getName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_getChildren(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_getChildren'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_getChildren'", nullptr);
            return 0;
        }
        const cocos2d::Vector<cocos2d::TinyxmlAccessor *>& ret = cobj->getChildren();
        ccvector_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:getChildren",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_getChildren'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_next(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_next'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_next'", nullptr);
            return 0;
        }
        bool ret = cobj->next();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:next",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_next'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_getProperties(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_getProperties'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_getProperties'", nullptr);
            return 0;
        }
        const cocos2d::ValueMap& ret = cobj->getProperties();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:getProperties",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_getProperties'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_onPopFromPool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_onPopFromPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_onPopFromPool'", nullptr);
            return 0;
        }
        cobj->onPopFromPool();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:onPopFromPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_onPopFromPool'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_onPushToPool(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlAccessor* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlAccessor*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlAccessor_onPushToPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_onPushToPool'", nullptr);
            return 0;
        }
        cobj->onPushToPool();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlAccessor:onPushToPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_onPushToPool'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlAccessor_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_create'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlAccessor* ret = cocos2d::TinyxmlAccessor::create();
        object_to_luaval<cocos2d::TinyxmlAccessor>(tolua_S, "cc.TinyxmlAccessor",(cocos2d::TinyxmlAccessor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TinyxmlAccessor:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_create'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_TinyxmlAccessor_resetPool(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_resetPool'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlAccessor::resetPool();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TinyxmlAccessor:resetPool",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_resetPool'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_TinyxmlAccessor_poolName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TinyxmlAccessor",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlAccessor_poolName'", nullptr);
            return 0;
        }
        const char* ret = cocos2d::TinyxmlAccessor::poolName();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TinyxmlAccessor:poolName",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlAccessor_poolName'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_TinyxmlAccessor_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TinyxmlAccessor)");
    return 0;
}

int lua_register_feather_TinyxmlAccessor(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TinyxmlAccessor");
    tolua_cclass(tolua_S,"TinyxmlAccessor","cc.TinyxmlAccessor","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"TinyxmlAccessor");
        tolua_function(tolua_S,"childrenWalker",lua_feather_TinyxmlAccessor_childrenWalker);
        tolua_function(tolua_S,"prev",lua_feather_TinyxmlAccessor_prev);
        tolua_function(tolua_S,"getProperty",lua_feather_TinyxmlAccessor_getProperty);
        tolua_function(tolua_S,"getParent",lua_feather_TinyxmlAccessor_getParent);
        tolua_function(tolua_S,"getName",lua_feather_TinyxmlAccessor_getName);
        tolua_function(tolua_S,"getChildren",lua_feather_TinyxmlAccessor_getChildren);
        tolua_function(tolua_S,"next",lua_feather_TinyxmlAccessor_next);
        tolua_function(tolua_S,"getProperties",lua_feather_TinyxmlAccessor_getProperties);
        tolua_function(tolua_S,"onPopFromPool",lua_feather_TinyxmlAccessor_onPopFromPool);
        tolua_function(tolua_S,"onPushToPool",lua_feather_TinyxmlAccessor_onPushToPool);
        tolua_function(tolua_S,"create", lua_feather_TinyxmlAccessor_create);
        tolua_function(tolua_S,"resetPool", lua_feather_TinyxmlAccessor_resetPool);
        tolua_function(tolua_S,"poolName", lua_feather_TinyxmlAccessor_poolName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TinyxmlAccessor).name();
    g_luaType[typeName] = "cc.TinyxmlAccessor";
    g_typeCast["TinyxmlAccessor"] = "cc.TinyxmlAccessor";
    return 1;
}

int lua_feather_TinyxmlDoc_getRoot(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::TinyxmlDoc* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.TinyxmlDoc",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::TinyxmlDoc*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_TinyxmlDoc_getRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlDoc_getRoot'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlAccessor* ret = cobj->getRoot();
        object_to_luaval<cocos2d::TinyxmlAccessor>(tolua_S, "cc.TinyxmlAccessor",(cocos2d::TinyxmlAccessor*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.TinyxmlDoc:getRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlDoc_getRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_TinyxmlDoc_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.TinyxmlDoc",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.TinyxmlDoc:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_TinyxmlDoc_create'", nullptr);
            return 0;
        }
        cocos2d::TinyxmlDoc* ret = cocos2d::TinyxmlDoc::create(arg0);
        object_to_luaval<cocos2d::TinyxmlDoc>(tolua_S, "cc.TinyxmlDoc",(cocos2d::TinyxmlDoc*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.TinyxmlDoc:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_TinyxmlDoc_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_TinyxmlDoc_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TinyxmlDoc)");
    return 0;
}

int lua_register_feather_TinyxmlDoc(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.TinyxmlDoc");
    tolua_cclass(tolua_S,"TinyxmlDoc","cc.TinyxmlDoc","cc.TinyxmlAccessor",nullptr);

    tolua_beginmodule(tolua_S,"TinyxmlDoc");
        tolua_function(tolua_S,"getRoot",lua_feather_TinyxmlDoc_getRoot);
        tolua_function(tolua_S,"create", lua_feather_TinyxmlDoc_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::TinyxmlDoc).name();
    g_luaType[typeName] = "cc.TinyxmlDoc";
    g_typeCast["TinyxmlDoc"] = "cc.TinyxmlDoc";
    return 1;
}

int lua_feather_NetFileDownloader_down(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::NetFileDownloader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::NetFileDownloader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_NetFileDownloader_down'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.NetFileDownloader:down");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_down'", nullptr);
            return 0;
        }
        cobj->down(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.NetFileDownloader:down");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.NetFileDownloader:down");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_down'", nullptr);
            return 0;
        }
        cobj->down(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.NetFileDownloader:down",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_down'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_NetFileDownloader_getRequestCount(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::NetFileDownloader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::NetFileDownloader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_NetFileDownloader_getRequestCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_getRequestCount'", nullptr);
            return 0;
        }
        int ret = cobj->getRequestCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.NetFileDownloader:getRequestCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_getRequestCount'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_NetFileDownloader_stop(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::NetFileDownloader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::NetFileDownloader*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_NetFileDownloader_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.NetFileDownloader:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_NetFileDownloader_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_destroyInstance'", nullptr);
            return 0;
        }
        cocos2d::NetFileDownloader::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.NetFileDownloader:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_NetFileDownloader_urlEncode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.NetFileDownloader:urlEncode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_urlEncode'", nullptr);
            return 0;
        }
        std::string ret = cocos2d::NetFileDownloader::urlEncode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.NetFileDownloader:urlEncode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_urlEncode'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_NetFileDownloader_urlDecode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.NetFileDownloader:urlDecode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_urlDecode'", nullptr);
            return 0;
        }
        std::string ret = cocos2d::NetFileDownloader::urlDecode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.NetFileDownloader:urlDecode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_urlDecode'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_NetFileDownloader_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.NetFileDownloader",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_getInstance'", nullptr);
            return 0;
        }
        cocos2d::NetFileDownloader* ret = cocos2d::NetFileDownloader::getInstance();
        object_to_luaval<cocos2d::NetFileDownloader>(tolua_S, "cc.NetFileDownloader",(cocos2d::NetFileDownloader*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.NetFileDownloader:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_feather_NetFileDownloader_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::NetFileDownloader* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_NetFileDownloader_constructor'", nullptr);
            return 0;
        }
        cobj = new cocos2d::NetFileDownloader();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.NetFileDownloader");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.NetFileDownloader:NetFileDownloader",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_feather_NetFileDownloader_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_feather_NetFileDownloader_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (NetFileDownloader)");
    return 0;
}

int lua_register_feather_NetFileDownloader(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.NetFileDownloader");
    tolua_cclass(tolua_S,"NetFileDownloader","cc.NetFileDownloader","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"NetFileDownloader");
        tolua_function(tolua_S,"new",lua_feather_NetFileDownloader_constructor);
        tolua_function(tolua_S,"down",lua_feather_NetFileDownloader_down);
        tolua_function(tolua_S,"getRequestCount",lua_feather_NetFileDownloader_getRequestCount);
        tolua_function(tolua_S,"stop",lua_feather_NetFileDownloader_stop);
        tolua_function(tolua_S,"destroyInstance", lua_feather_NetFileDownloader_destroyInstance);
        tolua_function(tolua_S,"urlEncode", lua_feather_NetFileDownloader_urlEncode);
        tolua_function(tolua_S,"urlDecode", lua_feather_NetFileDownloader_urlDecode);
        tolua_function(tolua_S,"getInstance", lua_feather_NetFileDownloader_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::NetFileDownloader).name();
    g_luaType[typeName] = "cc.NetFileDownloader";
    g_typeCast["NetFileDownloader"] = "cc.NetFileDownloader";
    return 1;
}

int lua_feather_AsyncSocket_destroy(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::AsyncSocket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.AsyncSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::AsyncSocket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_AsyncSocket_destroy'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_AsyncSocket_destroy'", nullptr);
            return 0;
        }
        cobj->destroy();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AsyncSocket:destroy",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_AsyncSocket_destroy'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_AsyncSocket_connectServer(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::AsyncSocket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.AsyncSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::AsyncSocket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_feather_AsyncSocket_connectServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.AsyncSocket:connectServer");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.AsyncSocket:connectServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_AsyncSocket_connectServer'", nullptr);
            return 0;
        }
        cobj->connectServer(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.AsyncSocket:connectServer",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_AsyncSocket_connectServer'.",&tolua_err);
#endif

    return 0;
}
int lua_feather_AsyncSocket_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.AsyncSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_feather_AsyncSocket_create'", nullptr);
            return 0;
        }
        cocos2d::AsyncSocket* ret = cocos2d::AsyncSocket::create();
        object_to_luaval<cocos2d::AsyncSocket>(tolua_S, "cc.AsyncSocket",(cocos2d::AsyncSocket*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.AsyncSocket:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_feather_AsyncSocket_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_feather_AsyncSocket_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AsyncSocket)");
    return 0;
}

int lua_register_feather_AsyncSocket(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.AsyncSocket");
    tolua_cclass(tolua_S,"AsyncSocket","cc.AsyncSocket","",nullptr);

    tolua_beginmodule(tolua_S,"AsyncSocket");
        tolua_function(tolua_S,"destroy",lua_feather_AsyncSocket_destroy);
        tolua_function(tolua_S,"connectServer",lua_feather_AsyncSocket_connectServer);
        tolua_function(tolua_S,"create", lua_feather_AsyncSocket_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::AsyncSocket).name();
    g_luaType[typeName] = "cc.AsyncSocket";
    g_typeCast["AsyncSocket"] = "cc.AsyncSocket";
    return 1;
}
TOLUA_API int register_all_feather(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_feather_SqliteWrapConnect(tolua_S);
	lua_register_feather_NetFileDownloader(tolua_S);
	lua_register_feather_AsyncSocket(tolua_S);
	lua_register_feather_ResourceLoader(tolua_S);
	lua_register_feather_SqliteWrapQuery(tolua_S);
	lua_register_feather_fc(tolua_S);
	lua_register_feather_ObjectPool(tolua_S);
	lua_register_feather_TinyxmlAccessor(tolua_S);
	lua_register_feather_TinyxmlDoc(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

