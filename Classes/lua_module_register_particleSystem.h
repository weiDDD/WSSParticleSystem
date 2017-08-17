#ifndef __LUA_MODULE_REGISTER_PARTICLE_SYSTEM_H__
#define __LUA_MODULE_REGISTER_PARTICLE_SYSTEM_H__



#include "lua_particle_system_auto.hpp"

int lua_module_register_ParticleSystem(lua_State* L)
{
	//Dont' change the module register order unless you know what your are doing
	register_all_particle_system(L);
	
	return 1;
}

#endif  // __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

