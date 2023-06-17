#pragma once
#ifndef __UPDATE_HELPER_H__
#define __UPDATE_HELPER_H__

#include "cocos2d.h"
#include "ParticleRenderer.h"
#include "ParticleEmitter.h"

using namespace PRender;
using namespace pp;

class UpdateHelper {
public:
	static UpdateHelper* instance;
	static UpdateHelper* getInstance();



	// 初始化一下sin，cos的缓存数据
	static void initSinCosChacheValue();

	// 获取缓存的sin,cos值
	static float getSinCacheValue(int angle);
	static float getCosCacheValue(int angle);

	// 将一个多边形划分成三角形集合 , polygonPoints 多边形的点集合 ，triangleVec 最终生成的三角形集合
	void changePolygonToTriangleVec(std::vector<Vec2>& polygonPoints, std::vector<triangle>* triangleVec);

	// 更新粒子的运动
	void updateParticleMove(particleProperty& p,float dt);

	//// 发射器的属性
	// 从 发射器 多样值中提取正确的 粒子属性 值
	float getValueFromEmitterVarietyValue(emitterVarietyValue& value, emitterFirePro& firePro);
	// 设置粒子生命周期内的属性
	void setParticleVarietyValue(particleVarietyValue &pValue, emitterVarietyValue &eValue, float pLife);

	// 从多样值中提取正确的 颜色 值
	Color3B getValueFromEmitterVarietyColorValue(emitterColorValue& value , emitterFirePro& firePro);
	// 设置粒子生命周期内的属性
	void setParticleVarietyColorValue(particleColorValue &pValue, emitterColorValue &eValue, float pLife);

	// // 根据发射器的数据来初始化粒子 属性
	void initParticlePro(ParticleEmitter* father,emitterFirePro& firePro ,particleProperty* particle);

	// 更新一个 发射属性
	void updateFirePro(ParticleEmitter* father , emitterFirePro& firePro, childrenPar& cPar, float dt);

public:
	
};


#endif // !__UPDATE_HELPER_H__
