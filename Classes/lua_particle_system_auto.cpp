#include "lua_particle_system_auto.hpp"
#include "ParticleEmitter.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_particle_system_ParticleEmitter_getFirstFirePro(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_getFirstFirePro'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_getFirstFirePro'", nullptr);
            return 0;
        }
        emitterFirePro* ret = cobj->getFirstFirePro();
        #pragma warning NO CONVERSION FROM NATIVE FOR emitterFirePro*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:getFirstFirePro",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_getFirstFirePro'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_readJsonDataFromFile(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_readJsonDataFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "pp.ParticleEmitter:readJsonDataFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_readJsonDataFromFile'", nullptr);
            return 0;
        }
        cobj->readJsonDataFromFile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:readJsonDataFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_readJsonDataFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_getIsActive(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_getIsActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_getIsActive'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsActive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:getIsActive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_getIsActive'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_varietyValue_pushCurveValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_pushCurveValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        int arg0;
        std::string arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_pushCurveValue'", nullptr);
            return 0;
        }
        cobj->setFirePro_varietyValue_pushCurveValue(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_varietyValue_pushCurveValue",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_pushCurveValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_duration(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_duration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_duration");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_duration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_duration'", nullptr);
            return 0;
        }
        cobj->setFirePro_duration(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_duration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_duration'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_getChildrenParById(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_getChildrenParById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:getChildrenParById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_getChildrenParById'", nullptr);
            return 0;
        }
        childrenPar* ret = cobj->getChildrenParById(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR childrenPar*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:getChildrenParById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_getChildrenParById'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushPolygonPoint(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushPolygonPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_fireArea_pushPolygonPoint");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_fireArea_pushPolygonPoint");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_fireArea_pushPolygonPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushPolygonPoint'", nullptr);
            return 0;
        }
        cobj->setFirePro_fireArea_pushPolygonPoint(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_fireArea_pushPolygonPoint",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushPolygonPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_MaxParticleNum(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_MaxParticleNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_MaxParticleNum");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "pp.ParticleEmitter:setFirePro_MaxParticleNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_MaxParticleNum'", nullptr);
            return 0;
        }
        cobj->setFirePro_MaxParticleNum(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_MaxParticleNum",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_MaxParticleNum'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_stopSystem(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_stopSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_stopSystem'", nullptr);
            return 0;
        }
        cobj->stopSystem();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:stopSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_stopSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_createEmitter(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_createEmitter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_createEmitter'", nullptr);
            return 0;
        }
        pp::ParticleEmitter* ret = cobj->createEmitter();
        object_to_luaval<pp::ParticleEmitter>(tolua_S, "pp.ParticleEmitter",(pp::ParticleEmitter*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:createEmitter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_createEmitter'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_fireArea_clear(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_fireArea_clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_clear'", nullptr);
            return 0;
        }
        cobj->setFirePro_fireArea_clear(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_fireArea_clear",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_emissionRate(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_emissionRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_emissionRate");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_emissionRate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_emissionRate'", nullptr);
            return 0;
        }
        cobj->setFirePro_emissionRate(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_emissionRate",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_emissionRate'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_removeFireProById(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_removeFireProById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:removeFireProById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_removeFireProById'", nullptr);
            return 0;
        }
        cobj->removeFireProById(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:removeFireProById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_removeFireProById'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_clearData(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_clearData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_clearData'", nullptr);
            return 0;
        }
        cobj->clearData();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:clearData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_clearData'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_colorValue_clear(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_colorValue_clear");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_colorValue_clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_clear'", nullptr);
            return 0;
        }
        cobj->setFirePro_colorValue_clear(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_colorValue_clear",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_ParType(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_ParType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_ParType");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_ParType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_ParType'", nullptr);
            return 0;
        }
        cobj->setFirePro_ParType(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_ParType",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_ParType'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_visit(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0);

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "pp.ParticleEmitter:visit");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "pp.ParticleEmitter:visit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_visit'", nullptr);
            return 0;
        }
        cobj->visit(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_colorValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 8) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg5;
            ok &= luaval_to_number(tolua_S, 7,&arg5, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg6;
            ok &= luaval_to_number(tolua_S, 8,&arg6, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg7;
            ok &= luaval_to_number(tolua_S, 9,&arg7, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            cobj->setFirePro_colorValue(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_colorValue");

            if (!ok) { break; }
            cobj->setFirePro_colorValue(arg0, arg1, arg2, arg3, arg4);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "pp.ParticleEmitter:setFirePro_colorValue",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_init(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_init'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_EmitterFileName(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_EmitterFileName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_EmitterFileName");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_EmitterFileName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_EmitterFileName'", nullptr);
            return 0;
        }
        cobj->setFirePro_EmitterFileName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_EmitterFileName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_EmitterFileName'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setIsAutoRemoveOnFinish(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setIsAutoRemoveOnFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "pp.ParticleEmitter:setIsAutoRemoveOnFinish");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setIsAutoRemoveOnFinish'", nullptr);
            return 0;
        }
        cobj->setIsAutoRemoveOnFinish(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setIsAutoRemoveOnFinish",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setIsAutoRemoveOnFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_FireAngleType(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_FireAngleType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_FireAngleType");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_FireAngleType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_FireAngleType'", nullptr);
            return 0;
        }
        cobj->setFirePro_FireAngleType(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_FireAngleType",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_FireAngleType'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_getFireProById(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_getFireProById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:getFireProById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_getFireProById'", nullptr);
            return 0;
        }
        emitterFirePro* ret = cobj->getFireProById(arg0);
        #pragma warning NO CONVERSION FROM NATIVE FOR emitterFirePro*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:getFireProById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_getFireProById'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_DestBlend(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_DestBlend'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_DestBlend");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "pp.ParticleEmitter:setFirePro_DestBlend");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_DestBlend'", nullptr);
            return 0;
        }
        cobj->setFirePro_DestBlend(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_DestBlend",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_DestBlend'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_releaseRender(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_releaseRender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_releaseRender'", nullptr);
            return 0;
        }
        cobj->releaseRender();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:releaseRender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_releaseRender'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_delayTime(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_delayTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_delayTime");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_delayTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_delayTime'", nullptr);
            return 0;
        }
        cobj->setFirePro_delayTime(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_delayTime",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_delayTime'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_tailPro(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 8) 
    {
        int arg0;
        std::string arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 8,&arg6, "pp.ParticleEmitter:setFirePro_tailPro");

        ok &= luaval_to_number(tolua_S, 9,&arg7, "pp.ParticleEmitter:setFirePro_tailPro");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro'", nullptr);
            return 0;
        }
        cobj->setFirePro_tailPro(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_tailPro",argc, 8);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_writeJsonData(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_writeJsonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        rapidjson::GenericDocument<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> > arg0;
        rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> arg1;

        ok &= luaval_to_object<rapidjson::GenericDocument<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> >>(tolua_S, 2, "rj.GenericDocument<rj.UTF8<char>, rj.MemoryPoolAllocator<rj.CrtAllocator> >",&arg0);

        ok &= luaval_to_object<rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>(tolua_S, 3, "rj.MemoryPoolAllocator<rj.CrtAllocator>",&arg1);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_writeJsonData'", nullptr);
            return 0;
        }
        bool ret = cobj->writeJsonData(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:writeJsonData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_writeJsonData'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_TexName(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_TexName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_TexName");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_TexName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_TexName'", nullptr);
            return 0;
        }
        cobj->setFirePro_TexName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_TexName",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_TexName'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_addOneFirePro(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_addOneFirePro'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        parType arg1;
        std::string arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:addOneFirePro");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "pp.ParticleEmitter:addOneFirePro");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "pp.ParticleEmitter:addOneFirePro");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_addOneFirePro'", nullptr);
            return 0;
        }
        emitterFirePro* ret = cobj->addOneFirePro(arg0, arg1, arg2);
        #pragma warning NO CONVERSION FROM NATIVE FOR emitterFirePro*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:addOneFirePro",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_addOneFirePro'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_colorValue_pushCurveValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_pushCurveValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        int arg0;
        std::string arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 8,&arg6, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 9,&arg7, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");

        ok &= luaval_to_number(tolua_S, 10,&arg8, "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_pushCurveValue'", nullptr);
            return 0;
        }
        cobj->setFirePro_colorValue_pushCurveValue(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_colorValue_pushCurveValue",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_colorValue_pushCurveValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_update(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "pp.ParticleEmitter:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_update'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_readJsonData(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_readJsonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        rapidjson::GenericDocument<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> > arg0;

        ok &= luaval_to_object<rapidjson::GenericDocument<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> >>(tolua_S, 2, "rj.GenericDocument<rj.UTF8<char>, rj.MemoryPoolAllocator<rj.CrtAllocator> >",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_readJsonData'", nullptr);
            return 0;
        }
        cobj->readJsonData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:readJsonData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_readJsonData'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirepro_varietyValue_pushMoreValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirepro_varietyValue_pushMoreValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirepro_varietyValue_pushMoreValue");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirepro_varietyValue_pushMoreValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirepro_varietyValue_pushMoreValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirepro_varietyValue_pushMoreValue'", nullptr);
            return 0;
        }
        cobj->setFirepro_varietyValue_pushMoreValue(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirepro_varietyValue_pushMoreValue",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirepro_varietyValue_pushMoreValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_resetSystem(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_resetSystem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_resetSystem'", nullptr);
            return 0;
        }
        cobj->resetSystem();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:resetSystem",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_resetSystem'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_fireArea(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            cobj->setFirePro_fireArea(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 5) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            double arg4;
            ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirePro_fireArea");

            if (!ok) { break; }
            cobj->setFirePro_fireArea(arg0, arg1, arg2, arg3, arg4);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "pp.ParticleEmitter:setFirePro_fireArea",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setRunningLayer(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setRunningLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setRunningLayer'", nullptr);
            return 0;
        }
        cobj->setRunningLayer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setRunningLayer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setRunningLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_getVarietyValueByType(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_getVarietyValueByType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        emitterFirePro* arg0;
        std::string arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR emitterFirePro*
		ok = false;

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:getVarietyValueByType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_getVarietyValueByType'", nullptr);
            return 0;
        }
        emitterVarietyValue* ret = cobj->getVarietyValueByType(arg0, arg1);
        #pragma warning NO CONVERSION FROM NATIVE FOR emitterVarietyValue*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:getVarietyValueByType",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_getVarietyValueByType'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_addRender(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_addRender'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_addRender'", nullptr);
            return 0;
        }
        cobj->addRender();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:addRender",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_addRender'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_varietyValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 4) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            double arg3;
            ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            cobj->setFirePro_varietyValue(arg0, arg1, arg2, arg3);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_varietyValue");

            if (!ok) { break; }
            cobj->setFirePro_varietyValue(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "pp.ParticleEmitter:setFirePro_varietyValue",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushLinePoint(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushLinePoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_fireArea_pushLinePoint");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_fireArea_pushLinePoint");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_fireArea_pushLinePoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushLinePoint'", nullptr);
            return 0;
        }
        cobj->setFirePro_fireArea_pushLinePoint(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_fireArea_pushLinePoint",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushLinePoint'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_AnchorPoint(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_AnchorPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_AnchorPoint");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_AnchorPoint");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirePro_AnchorPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_AnchorPoint'", nullptr);
            return 0;
        }
        cobj->setFirePro_AnchorPoint(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_AnchorPoint",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_AnchorPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_SourceBlend(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_SourceBlend'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_SourceBlend");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "pp.ParticleEmitter:setFirePro_SourceBlend");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_SourceBlend'", nullptr);
            return 0;
        }
        cobj->setFirePro_SourceBlend(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_SourceBlend",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_SourceBlend'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_varietyValue_clear(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_varietyValue_clear");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_varietyValue_clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_clear'", nullptr);
            return 0;
        }
        cobj->setFirePro_varietyValue_clear(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_varietyValue_clear",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_varietyValue_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_isLoop(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_isLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_isLoop");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_isLoop");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_isLoop'", nullptr);
            return 0;
        }
        cobj->setFirePro_isLoop(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_isLoop",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_isLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirepro_colorValue_pushMoreValue(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirepro_colorValue_pushMoreValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        int arg0;
        std::string arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirepro_colorValue_pushMoreValue'", nullptr);
            return 0;
        }
        cobj->setFirepro_colorValue_pushMoreValue(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirepro_colorValue_pushMoreValue",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirepro_colorValue_pushMoreValue'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_refreshZorder(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_refreshZorder'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_refreshZorder'", nullptr);
            return 0;
        }
        cobj->refreshZorder();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:refreshZorder",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_refreshZorder'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_tailPro_isActive(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro_isActive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_tailPro_isActive");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_tailPro_isActive");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro_isActive'", nullptr);
            return 0;
        }
        cobj->setFirePro_tailPro_isActive(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_tailPro_isActive",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_tailPro_isActive'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_preFireDuration(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_preFireDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_preFireDuration");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_preFireDuration");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_preFireDuration'", nullptr);
            return 0;
        }
        cobj->setFirePro_preFireDuration(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_preFireDuration",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_preFireDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setFirePro_PositionType(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setFirePro_PositionType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::string arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "pp.ParticleEmitter:setFirePro_PositionType");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "pp.ParticleEmitter:setFirePro_PositionType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setFirePro_PositionType'", nullptr);
            return 0;
        }
        cobj->setFirePro_PositionType(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setFirePro_PositionType",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setFirePro_PositionType'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_setTestData(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (pp::ParticleEmitter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_particle_system_ParticleEmitter_setTestData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        emitterFirePro arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR emitterFirePro
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setTestData'", nullptr);
            return 0;
        }
        cobj->setTestData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:setTestData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setTestData'.",&tolua_err);
#endif

    return 0;
}
int lua_particle_system_ParticleEmitter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            bool arg0;
            ok &= luaval_to_boolean(tolua_S, 2,&arg0, "pp.ParticleEmitter:create");
            if (!ok) { break; }
            pp::ParticleEmitter* ret = pp::ParticleEmitter::create(arg0);
            object_to_luaval<pp::ParticleEmitter>(tolua_S, "pp.ParticleEmitter",(pp::ParticleEmitter*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            pp::ParticleEmitter* ret = pp::ParticleEmitter::create();
            object_to_luaval<pp::ParticleEmitter>(tolua_S, "pp.ParticleEmitter",(pp::ParticleEmitter*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "pp.ParticleEmitter:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_create'.",&tolua_err);
#endif
    return 0;
}
int lua_particle_system_ParticleEmitter_setSourcePath(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"pp.ParticleEmitter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "pp.ParticleEmitter:setSourcePath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_setSourcePath'", nullptr);
            return 0;
        }
        pp::ParticleEmitter::setSourcePath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "pp.ParticleEmitter:setSourcePath",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_setSourcePath'.",&tolua_err);
#endif
    return 0;
}
int lua_particle_system_ParticleEmitter_constructor(lua_State* tolua_S)
{
    int argc = 0;
    pp::ParticleEmitter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_particle_system_ParticleEmitter_constructor'", nullptr);
            return 0;
        }
        cobj = new pp::ParticleEmitter();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"pp.ParticleEmitter");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "pp.ParticleEmitter:ParticleEmitter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_particle_system_ParticleEmitter_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_particle_system_ParticleEmitter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ParticleEmitter)");
    return 0;
}

int lua_register_particle_system_ParticleEmitter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"pp.ParticleEmitter");
    tolua_cclass(tolua_S,"ParticleEmitter","pp.ParticleEmitter","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"ParticleEmitter");
        tolua_function(tolua_S,"new",lua_particle_system_ParticleEmitter_constructor);
        tolua_function(tolua_S,"getFirstFirePro",lua_particle_system_ParticleEmitter_getFirstFirePro);
        tolua_function(tolua_S,"readJsonDataFromFile",lua_particle_system_ParticleEmitter_readJsonDataFromFile);
        tolua_function(tolua_S,"getIsActive",lua_particle_system_ParticleEmitter_getIsActive);
        tolua_function(tolua_S,"setFirePro_varietyValue_pushCurveValue",lua_particle_system_ParticleEmitter_setFirePro_varietyValue_pushCurveValue);
        tolua_function(tolua_S,"setFirePro_duration",lua_particle_system_ParticleEmitter_setFirePro_duration);
        tolua_function(tolua_S,"getChildrenParById",lua_particle_system_ParticleEmitter_getChildrenParById);
        tolua_function(tolua_S,"setFirePro_fireArea_pushPolygonPoint",lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushPolygonPoint);
        tolua_function(tolua_S,"setFirePro_MaxParticleNum",lua_particle_system_ParticleEmitter_setFirePro_MaxParticleNum);
        tolua_function(tolua_S,"stopSystem",lua_particle_system_ParticleEmitter_stopSystem);
        tolua_function(tolua_S,"createEmitter",lua_particle_system_ParticleEmitter_createEmitter);
        tolua_function(tolua_S,"setFirePro_fireArea_clear",lua_particle_system_ParticleEmitter_setFirePro_fireArea_clear);
        tolua_function(tolua_S,"setFirePro_emissionRate",lua_particle_system_ParticleEmitter_setFirePro_emissionRate);
        tolua_function(tolua_S,"removeFireProById",lua_particle_system_ParticleEmitter_removeFireProById);
        tolua_function(tolua_S,"clearData",lua_particle_system_ParticleEmitter_clearData);
        tolua_function(tolua_S,"setFirePro_colorValue_clear",lua_particle_system_ParticleEmitter_setFirePro_colorValue_clear);
        tolua_function(tolua_S,"setFirePro_ParType",lua_particle_system_ParticleEmitter_setFirePro_ParType);
        tolua_function(tolua_S,"visit",lua_particle_system_ParticleEmitter_visit);
        tolua_function(tolua_S,"setFirePro_colorValue",lua_particle_system_ParticleEmitter_setFirePro_colorValue);
        tolua_function(tolua_S,"init",lua_particle_system_ParticleEmitter_init);
        tolua_function(tolua_S,"setFirePro_EmitterFileName",lua_particle_system_ParticleEmitter_setFirePro_EmitterFileName);
        tolua_function(tolua_S,"setIsAutoRemoveOnFinish",lua_particle_system_ParticleEmitter_setIsAutoRemoveOnFinish);
        tolua_function(tolua_S,"setFirePro_FireAngleType",lua_particle_system_ParticleEmitter_setFirePro_FireAngleType);
        tolua_function(tolua_S,"getFireProById",lua_particle_system_ParticleEmitter_getFireProById);
        tolua_function(tolua_S,"setFirePro_DestBlend",lua_particle_system_ParticleEmitter_setFirePro_DestBlend);
        tolua_function(tolua_S,"releaseRender",lua_particle_system_ParticleEmitter_releaseRender);
        tolua_function(tolua_S,"setFirePro_delayTime",lua_particle_system_ParticleEmitter_setFirePro_delayTime);
        tolua_function(tolua_S,"setFirePro_tailPro",lua_particle_system_ParticleEmitter_setFirePro_tailPro);
        tolua_function(tolua_S,"writeJsonData",lua_particle_system_ParticleEmitter_writeJsonData);
        tolua_function(tolua_S,"setFirePro_TexName",lua_particle_system_ParticleEmitter_setFirePro_TexName);
        tolua_function(tolua_S,"addOneFirePro",lua_particle_system_ParticleEmitter_addOneFirePro);
        tolua_function(tolua_S,"setFirePro_colorValue_pushCurveValue",lua_particle_system_ParticleEmitter_setFirePro_colorValue_pushCurveValue);
        tolua_function(tolua_S,"update",lua_particle_system_ParticleEmitter_update);
        tolua_function(tolua_S,"readJsonData",lua_particle_system_ParticleEmitter_readJsonData);
        tolua_function(tolua_S,"setFirepro_varietyValue_pushMoreValue",lua_particle_system_ParticleEmitter_setFirepro_varietyValue_pushMoreValue);
        tolua_function(tolua_S,"resetSystem",lua_particle_system_ParticleEmitter_resetSystem);
        tolua_function(tolua_S,"setFirePro_fireArea",lua_particle_system_ParticleEmitter_setFirePro_fireArea);
        tolua_function(tolua_S,"setRunningLayer",lua_particle_system_ParticleEmitter_setRunningLayer);
        tolua_function(tolua_S,"getVarietyValueByType",lua_particle_system_ParticleEmitter_getVarietyValueByType);
        tolua_function(tolua_S,"addRender",lua_particle_system_ParticleEmitter_addRender);
        tolua_function(tolua_S,"setFirePro_varietyValue",lua_particle_system_ParticleEmitter_setFirePro_varietyValue);
        tolua_function(tolua_S,"setFirePro_fireArea_pushLinePoint",lua_particle_system_ParticleEmitter_setFirePro_fireArea_pushLinePoint);
        tolua_function(tolua_S,"setFirePro_AnchorPoint",lua_particle_system_ParticleEmitter_setFirePro_AnchorPoint);
        tolua_function(tolua_S,"setFirePro_SourceBlend",lua_particle_system_ParticleEmitter_setFirePro_SourceBlend);
        tolua_function(tolua_S,"setFirePro_varietyValue_clear",lua_particle_system_ParticleEmitter_setFirePro_varietyValue_clear);
        tolua_function(tolua_S,"setFirePro_isLoop",lua_particle_system_ParticleEmitter_setFirePro_isLoop);
        tolua_function(tolua_S,"setFirepro_colorValue_pushMoreValue",lua_particle_system_ParticleEmitter_setFirepro_colorValue_pushMoreValue);
        tolua_function(tolua_S,"refreshZorder",lua_particle_system_ParticleEmitter_refreshZorder);
        tolua_function(tolua_S,"setFirePro_tailPro_isActive",lua_particle_system_ParticleEmitter_setFirePro_tailPro_isActive);
        tolua_function(tolua_S,"setFirePro_preFireDuration",lua_particle_system_ParticleEmitter_setFirePro_preFireDuration);
        tolua_function(tolua_S,"setFirePro_PositionType",lua_particle_system_ParticleEmitter_setFirePro_PositionType);
        tolua_function(tolua_S,"setTestData",lua_particle_system_ParticleEmitter_setTestData);
        tolua_function(tolua_S,"create", lua_particle_system_ParticleEmitter_create);
        tolua_function(tolua_S,"setSourcePath", lua_particle_system_ParticleEmitter_setSourcePath);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(pp::ParticleEmitter).name();
    g_luaType[typeName] = "pp.ParticleEmitter";
    g_typeCast["ParticleEmitter"] = "pp.ParticleEmitter";
    return 1;
}
TOLUA_API int register_all_particle_system(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"pp",0);
	tolua_beginmodule(tolua_S,"pp");

	lua_register_particle_system_ParticleEmitter(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

