/*
	add by wss 16/6/24

	为cocos的spine增加接口
*/

#ifndef LUA_SPSKELETONDATA_H
#define LUA_SPSKELETONDATA_H

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

//TOLUA_API int
TOLUA_API int register_spSkeletonData_manual(lua_State* L);

#endif
