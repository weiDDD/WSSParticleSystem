#include "ParticleEmitter.h"
#include "UpdateHelper.h"
#include "FileCenter.h"

using namespace pp;

int ParticleEmitter::updatePriority = 200;
int ParticleEmitter::fireProId = 1;

bool ParticleEmitter::isUseDrawNode = false;
bool ParticleEmitter::isUiEditorModel = false;

static long getNowTime(){
	struct timeval now;
	gettimeofday(&now,NULL);
	return now.tv_usec;
}

static float logTimeValue = 3;
static float logTimeCount = logTimeValue;
static float debugTime1 = 0;
static float debugTime2 = 0;
static float debugTime3 = 0;
static float debugTime4 = 0;
static float debugTime5 = 0;
static float debugTime6 = 0;

static float debugTime7 = 0;
static float debugTime8 = 0;
static float debugTime9 = 0;

void childrenPar::setTotalParticles(int tp, Node* father,std::string emitterFileName) {
	if (_renderer) {
		_renderer->setTotalParticles(tp);
	}
	else {
		_totalParticles = tp;
		int size = _emitter.size();
		if (tp > size) {
			for (int i = size; i < tp; i++) {
				emitterPar* ePar = new emitterPar();
				ePar->par = ParticleEmitter::create();
				if (emitterFileName != "") {
					ePar->par->readJsonData(FileCenter::getInstance()->readJsonData(ParticleEmitter::sourcePath + emitterFileName));
				}
				ePar->par->unscheduleUpdate();
				ePar->par->setVisible(false);
				father->addChild(ePar->par);
				_emitter.push_back(ePar);
			}
		}
		else if (tp < size) {
			if (_particleCount > tp) {
				_particleCount = tp;
			}

			auto itor = _emitter.begin() + tp;
			while (itor != _emitter.end()) {
				auto ePar = (*itor);
				if (ePar->par) {
					ePar->par->removeFromParent();
					ePar->par = nullptr;
				}
				delete ePar;
				itor = _emitter.erase(itor);
				continue;
				itor++;
			}

		}
	}
}

particleProperty* childrenPar::addParticle(Node* father, std::string emitterFileName , int localZorder) {

	if (_renderer) {
		if (_renderer->isFull()) {
			return nullptr;
		}
		particleProperty* particle = _renderer->getNewParticlePtr();
		particle->resetData();
		//UpdateHelper::getInstance()->initParticlePro(this, firePro, particle);
		_renderer->addParticleCount();
		

		return particle;

	}
	else {
		if (_particleCount < _totalParticles) {
			/*emitterPar* ePar = new emitterPar();
			ePar->par = ParticleEmitter::create();
			if (emitterFileName != ""){
				ePar->par->readJsonData(FileCenter::getInstance()->readJsonData("json/"+emitterFileName));
			}
			father->addChild(ePar->par);
			_emitter.push_back(ePar);
			_particleCount++;
			return &ePar->pro;*/

			auto ePar = _emitter[_particleCount];
			/*if (emitterFileName != "") {
				ePar->par->readJsonData(FileCenter::getInstance()->readJsonData("json/" + emitterFileName));
			}*/

			// 如果有runningLayer就直接加，没有会自己加
			if (ePar->par->runningLayer) {
				ePar->par->addRender();
			}

			ePar->par->scheduleUpdate();
			ePar->par->setVisible(true);
			ePar->par->resetSystem();
			ePar->par->setLocalZOrder(localZorder);
			ePar->pro.resetData();
			++_particleCount;
			return &ePar->pro;
		}
	}
	return nullptr;
}

void childrenPar::resetData() {
	if (_renderer) {
		_renderer->stopAllParticles();
	}
	else {
		//_totalParticles = 0;
		_particleCount = 0;
		auto itor = _emitter.begin();
		while (itor != _emitter.end()) {
			(*itor)->par->releaseRender();

			(*itor)->par->unscheduleUpdate();
			(*itor)->par->setVisible(false);
			(*itor)->pro.resetData();

			itor++;
		}
	}
}

void childrenPar::clearData() {
	if (_renderer) {
		
		_renderer->removeFromParent();
		
		if (ParticleRenderer::cacheSize >= ParticleRenderer::maxCacheSize) {
			_renderer->release();
		}
		else {
			ParticleRenderer::renderCache.at(ParticleRenderer::cacheSize) = _renderer;
			++ParticleRenderer::cacheSize;
		}
		_renderer->setParticleCount(0);
		_renderer->_emitter = nullptr;
		_renderer = nullptr;
	}
	for (int i = 0; i < _emitter.size(); ++i) {
		if (_emitter[i]->par) {
			_emitter[i]->par->clearData();
			_emitter[i]->par->removeFromParent();
			_emitter[i]->par = nullptr;
		}
		delete _emitter[i];
	}
	_emitter.clear();
}

void childrenPar::updateOneParticle(particleProperty& p, float dt, bool isUpdateRender/* = true*/) {
	if (_renderer) {
		_renderer->updateOneParticle(p, dt, isUpdateRender);
	}
	else {
		p.timeToLive -= dt;
		UpdateHelper::instance->updateParticleMove(p, dt);
	}
}

void varietyFireAreaValue::setPolygonAndLineAreaLineDis() {
	polygonLinesDis.clear();
	int polygonPointSize = polygonPoints.size();
	if (polygonPointSize >= 3) {
		for (int i = 0; i < polygonPointSize; ++i) {
			Vec2 point1 = polygonPoints[i];
			Vec2 point2;
			if (i == polygonPointSize - 1) {
				point2 = polygonPoints[0];
			}
			else {
				point2 = polygonPoints[i + 1];
			}
			polygonLinesDis.push_back(point1.getDistance(point2));
		}
	}
	////
	lineLinesDis.clear();
	int linePointSize = linePoints.size();
	if (linePointSize >= 2) {
		for (int i = 0; i < linePointSize - 1; ++i) {
			Vec2 point1 = linePoints[i];
			Vec2 point2 = linePoints[i + 1];
			lineLinesDis.push_back(point1.getDistance(point2));
		}
	}

}


void tailPro::refreshTailData() {
	if (tailNode) {
		//tailNode->initWithFade(fade, minSeg, stroke, color, "tail/" + tailName);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string ParticleEmitter::sourcePath = "";
void ParticleEmitter::setSourcePath(std::string path) {
	ParticleEmitter::sourcePath = path;
}
// 纹理的路径
std::string ParticleEmitter::texturePath = "";
void ParticleEmitter::setTexturePath(std::string path) {
	ParticleEmitter::texturePath = path;
}

void ParticleEmitter::setRunningLayer(Node* layer) {
	this->runningLayer = layer;
	this->addRender();
}

ParticleEmitter::ParticleEmitter()
{
	runningLayer = nullptr;
	_isActive = false;
	_isAutoRemoveOnFinish = false;
	worldPos = Vec2(0, 0);

	fScaleX = 0;
	fScaleY = 0;
}

ParticleEmitter::~ParticleEmitter() {
	// 当发射器死亡时，将render释放给runningLayer , 
	//assert(this->runningLayer, "particle Emitter must set runningLayer , runningLayer is null !");

	this->releaseRender();   // 先清理render
	this->clearData();       // 清理数据
}

ParticleEmitter* ParticleEmitter::instance;

ParticleEmitter* ParticleEmitter::create() {
	ParticleEmitter* emitter = new ParticleEmitter();
	if (emitter && emitter->init()) {
		emitter->autorelease();
		return emitter;
	}
	CC_SAFE_DELETE(emitter);
	return emitter;
}

ParticleEmitter* ParticleEmitter::create(bool isInstance) {
	if (ParticleEmitter::instance) {
		return ParticleEmitter::instance->createEmitter();
	}
	return nullptr;
}

ParticleEmitter* ParticleEmitter::createEmitter() {
	ParticleEmitter* emitter = new ParticleEmitter();
	if (emitter && emitter->init()) {
		emitter->autorelease();
		return emitter;
	}
	CC_SAFE_DELETE(emitter);
	return emitter;
}

void ParticleEmitter::onEnter() {
#if CC_ENABLE_SCRIPT_BINDING
	if (_scriptType == kScriptTypeJavascript)
	{
		if (ScriptEngineManager::sendNodeEventToJSExtended(this, kNodeOnEnter))
			return;
	}
#endif

	Node::onEnter();

	// update after action in run!
	/*this->scheduleUpdateWithPriority(ParticleEmitter::updatePriority);
	ParticleEmitter::updatePriority++;
	if (ParticleEmitter::updatePriority > 400) {
		ParticleEmitter::updatePriority = 200;
	}*/

	this->scheduleUpdate();

	

}
void ParticleEmitter::onExit() {
	this->worldPos = this->convertToWorldSpace(Vec2(0, 0));
	this->getFatherScale();

	Node::onExit();
	//this->unscheduleUpdate();
	//this->stopSystem();
	//_renderer->_emitter = nullptr;
	
}

emitterFirePro* ParticleEmitter::addOneFirePro(int id,parType type, std::string fileName) {
	// 加一个 firePro
	

	int targetId = id;
	if (id == -1) {
		targetId = ParticleEmitter::fireProId;
		ParticleEmitter::fireProId++;
	}
	else {
		targetId = id;
		//firePro->_id = id;
		if (targetId >= ParticleEmitter::fireProId) {
			ParticleEmitter::fireProId = targetId + 1;
		}
	}

	emitterFirePro* firePro = this->getFireProById(targetId);

	if (!firePro) {
		firePro = new emitterFirePro();
		fireProVec.push_back(firePro);
	}

	firePro->_id = targetId;
	firePro->_parType = type;
	

	auto itor = childrenParMap.find(targetId);
	if (itor == childrenParMap.end()) {
		childrenPar* cPar = new childrenPar();
		if (firePro->_parType == parType::render) {
		}
		else if (firePro->_parType == parType::emitter) {
			if (fileName != "") {
				firePro->_emitterFileName = fileName;
			}
		}
		childrenParMap.insert(std::make_pair(firePro->_id, cPar));
	}

	return firePro;
}

bool ParticleEmitter::init() {
	//return initWithTotalParticles(150);
	// 启用
	_isActive = true;

	//this->addOneFirePro(parType::render,"");

	//this->addOneFirePro(parType::render, "");

	//this->scheduleUpdate();
	
	return true;
}

void ParticleEmitter::clearData() {
	// clear
	{
		auto itor = fireProVec.begin();
		while (itor != fireProVec.end()) {
			delete (*itor);
			itor++;
		}
		fireProVec.clear();
	}

	auto itor = childrenParMap.begin();
	while (itor != childrenParMap.end()) {
		auto cPar = (*itor).second;
		cPar->clearData();
		delete cPar;
		itor++;
	}
	childrenParMap.clear();

}

void ParticleEmitter::refreshZorder() {

	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		auto firePro = (*itor);
		if (firePro->_parType == parType::render) {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				if (cPar->second->_renderer)
				{
					cPar->second->_renderer->setLocalZOrder(firePro->_localZorder);
					
				}
			}
		}
		else if (firePro->_parType == parType::emitter) {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				int emitterSize = cPar->second->_emitter.size();
				for (int i = 0; i < emitterSize; ++i) {
					cPar->second->_emitter[i]->par->setLocalZOrder(firePro->_localZorder);
				}

			}
		}

		itor++;
	}
}

void ParticleEmitter::setTestData(emitterFirePro& firePro) {

	firePro._texName = "texture/parnocolor.png";

	firePro._positionType = positionType::RELATIVE;
	firePro._emissionRate = 10;
	firePro._duration = 3;
	firePro._isLoop = true;
	firePro._preFireDuration = 0;
	firePro._delayTime = 0;
	firePro._maxParticleNum = 100;
	firePro._angleType = fireAngleType::local;

	// -------------------- 发射区域
	firePro._fireArea.fAreaType = fireAreaType::circle;
	firePro._fireArea.inCircleRadius = 0;
	firePro._fireArea.outCircleRadius = 0;

	// ----------------- 生命
	firePro._life.pType = emitterPropertyType::randBetweenTwoConst;
	firePro._life.randConst1 = 1;
	firePro._life.randConst2 = 3;

	
	// ----------------- 移动速度
	firePro._startMoveSpeed.pType = emitterPropertyType::randBetweenTwoConst;
	firePro._startMoveSpeed.randConst1 = 100;
	firePro._startMoveSpeed.randConst2 = 150;

	// ---------------- 加速度
	firePro._startMoveAcc.pType = emitterPropertyType::oneConstant;
	firePro._startMoveAcc.constValue = 0;

	// ---------------- 移动角度
	firePro._startMoveAngle.pType = emitterPropertyType::randBetweenTwoConst;
	firePro._startMoveAngle.randConst1 = 0;
	firePro._startMoveAngle.randConst2 = 360;

	// ----------------- 角速度
	firePro._startMoveAngleSpeed.pType = emitterPropertyType::oneConstant;
	firePro._startMoveAngleSpeed.constValue = 0;

	// ----------------- 重力X
	firePro._startGravityX.pType = emitterPropertyType::oneConstant;
	firePro._startGravityX.constValue = 0;
	// ----------------- 重力Y
	firePro._startGravityY.pType = emitterPropertyType::oneConstant;
	firePro._startGravityY.constValue = 0;


	// ----------------- 大小
	firePro._startSize.pType = emitterPropertyType::oneConstant;
	firePro._startSize.constValue = 50;

	// ----------------- 旋转角度
	firePro._startRotation.pType = emitterPropertyType::randBetweenTwoConst;
	firePro._startRotation.randConst1 = 0;
	firePro._startRotation.randConst2 = 360;

	// ----------------- 旋转速度
	firePro._startRotationSpeed.pType = emitterPropertyType::oneConstant;
	firePro._startRotationSpeed.constValue = 0;

	firePro._startRotationSpeed.pType = emitterPropertyType::randBetweenTwoConst;
	firePro._startRotationSpeed.randConst1 = -30;
	firePro._startRotationSpeed.randConst2 = 30;

	// ----------------- 倾斜角X
	firePro._startSkewX.pType = emitterPropertyType::oneConstant;
	firePro._startSkewX.constValue = 0;

	// ----------------- 倾斜角X 速度
	firePro._startSkewXSpeed.pType = emitterPropertyType::oneConstant;
	firePro._startSkewXSpeed.constValue = 0;

	// ----------------- 倾斜角Y
	firePro._startSkewY.pType = emitterPropertyType::oneConstant;
	firePro._startSkewY.constValue = 0;

	// ----------------- 倾斜角Y 速度
	firePro._startSkewYSpeed.pType = emitterPropertyType::oneConstant;
	firePro._startSkewYSpeed.constValue = 0;

	// ----------------- 不透明度
	
	firePro._startAlpha.pType = emitterPropertyType::oneConstant;
	firePro._startAlpha.constValue = 250;

	// ----------------- 颜色
	firePro._startColor.pType = emitterPropertyType::oneConstant;
	firePro._startColor.constColor = Color3B(0,255,255);

}

void ParticleEmitter::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) {
	Node::visit(renderer , parentTransform, parentFlags);
}

childrenPar* ParticleEmitter::getChildrenParById(int id) {
	auto map_itor = childrenParMap.find(id);
	if (map_itor != childrenParMap.end()) {
		return (*map_itor).second;
	}
	return nullptr;
}
void ParticleEmitter::setChildrenParNewId(int oldid, int newid) {
	auto map_itor = childrenParMap.find(oldid);
	if (map_itor != childrenParMap.end()) {
		childrenPar* cPar = (*map_itor).second;
		childrenParMap.erase(map_itor);
		childrenParMap.insert(std::make_pair(newid, cPar));
	}
}

void ParticleEmitter::removeFireProById(int id) {
	
	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		if (id == (*itor)->_id) {
			delete (*itor);
			fireProVec.erase(itor);
			break;
		}
		itor++;
	}

	auto map_itor = childrenParMap.find(id);
	if (map_itor != childrenParMap.end()) {
		auto cPar = (*map_itor).second;
		cPar->clearData();
		delete cPar;
		childrenParMap.erase(map_itor);
	}
}

void ParticleEmitter::addRender(bool isCreateNew /*= false*/) {
	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		auto firePro = (*itor);
		if (firePro->_parType == parType::render) {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				if (!cPar->second->_renderer)
				{
					
					/*cPar->second->_renderer = ParticleRenderer::create();
					cPar->second->_renderer->initWithTotalParticles(1);
					cPar->second->_renderer->setTexture(CCTextureCache::sharedTextureCache()->addImage(firePro->_texName));
					this->addChild(cPar->second->_renderer , firePro->_localZorder);
					cPar->second->_renderer->_emitter = this;*/

					if (!isCreateNew && ParticleRenderer::cacheSize > 0) {
						cPar->second->_renderer = ParticleRenderer::renderCache.at(ParticleRenderer::cacheSize - 1) ;
						ParticleRenderer::renderCache.at(ParticleRenderer::cacheSize - 1) = nullptr;
						--ParticleRenderer::cacheSize;
					}

					if (!cPar->second->_renderer){
						cPar->second->_renderer = ParticleRenderer::create();
						cPar->second->_renderer->initWithTotalParticles(1);

						if (firePro->_isFlowCircleRadius) {
							cPar->second->_renderer->isFlowCircleRadius = true;
							cPar->second->_renderer->flowCircleRadiusFireProId = firePro->_id;
						}
					}
					cPar->second->_renderer->setIsAutoRemoveOnFinish(false);
					cPar->second->_renderer->_emitter = this;
					cPar->second->_renderer->setPosition(Vec2::ZERO);
					
					cPar->second->_renderer->setTexture(CCTextureCache::sharedTextureCache()->addImage(firePro->_texName));

					if (firePro->_positionType == positionType::FREE) {
						this->runningLayer->addChild(cPar->second->_renderer, firePro->_localZorder);
					}
					else if (firePro->_positionType == positionType::RELATIVE) {
						this->addChild(cPar->second->_renderer, firePro->_localZorder);
					}

				}
			}
		}

		itor++;
	}
}

void ParticleEmitter::releaseRender() {
	//this->worldPos = this->convertToWorldSpace(Vec2::ZERO);
	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		auto firePro = (*itor);
		if (firePro->_parType == parType::render) {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				if (cPar->second->_renderer)
				{
					if (this->runningLayer && this->runningLayer->isRunning()) {
						if (firePro->_positionType == positionType::FREE) {
							if (UpdateHelper::getInstance()->getValueFromEmitterVarietyValue(firePro->_life, *firePro) >= 1000) {
								cPar->second->_renderer->removeFromParent();
								cPar->second->_renderer->release();
								cPar->second->_renderer->_emitter = nullptr;
								cPar->second->_renderer = nullptr;
							}
							else {
								cPar->second->_renderer->scheduleUpdateWithPriority(1);
								cPar->second->_renderer->setIsAutoRemoveOnFinish(true);
								cPar->second->_renderer->_emitter = nullptr;
								cPar->second->_renderer = nullptr;
							}

						}
						else if (firePro->_positionType == positionType::RELATIVE) {
							if (UpdateHelper::getInstance()->getValueFromEmitterVarietyValue(firePro->_life, *firePro) >= 1000) {
								// 如果是生命值无限长的话，那么就得直接删掉这个render
								cPar->second->_renderer->removeFromParent();
								cPar->second->_renderer->release();
								cPar->second->_renderer->_emitter = nullptr;
								cPar->second->_renderer = nullptr;
							}
							else {
								// 不是无限长的生命，需要加到runningLayer上自死亡
								
								cPar->second->_renderer->removeFromParent();
								this->runningLayer->addChild(cPar->second->_renderer);
								//Vec2 parentPos = this->convertToWorldSpace(Vec2(0, 0));
								//parentPos = this->runningLayer->convertToNodeSpace(parentPos);
								cPar->second->_renderer->setPosition(this->worldPos);
								cPar->second->_renderer->scheduleUpdateWithPriority(1);

								cPar->second->_renderer->setScaleX(fScaleX);
								cPar->second->_renderer->setScaleY(fScaleY);
								// 放完自死
								cPar->second->_renderer->setIsAutoRemoveOnFinish(true);
								cPar->second->_renderer->_emitter = nullptr;
								cPar->second->_renderer = nullptr;
							}
						}
					}
					else {
						cPar->second->_renderer->removeFromParent();
						cPar->second->_renderer->release();
						cPar->second->_renderer->_emitter = nullptr;
						cPar->second->_renderer = nullptr;
					}
				}
			}
		}
		else {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				for (int i = 0; i < cPar->second->_emitter.size(); ++i) {
					auto ePar = cPar->second->_emitter[i]->par;
					ePar->retain();
					ePar->removeFromParent();
					this->runningLayer->addChild(ePar);
					//Vec2 parentPos = this->convertToWorldSpace(Vec2::ZERO);
					ePar->setPosition(this->worldPos);
					ePar->release();
					ePar->scheduleUpdateWithPriority(int(CCRANDOM_0_1() * 200));
					// 放完自死
					ePar->setIsAutoRemoveOnFinish(true);
				}
				cPar->second->_emitter.clear();
			}
		}
		++itor;
	}
}

void ParticleEmitter::getFatherScale() {
	fScaleX = 1;
	fScaleY = 1;
	auto parent = (Node*)this;
	while (true) {
		float scaleX = parent->getScaleX();
		float scaleY = parent->getScaleY();
		fScaleX *= scaleX;
		fScaleY *= scaleY;

		parent = parent->getParent();
		if (!parent) {
			break;
		}
	}
}

void ParticleEmitter::clearRender() {
	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		auto firePro = (*itor);
		if (firePro->_parType == parType::render) {
			auto cPar = childrenParMap.find(firePro->_id);
			if (cPar != childrenParMap.end()) {
				if (cPar->second->_renderer)
				{
					
					cPar->second->_renderer->removeFromParent();
					cPar->second->_renderer->release();
					cPar->second->_renderer = nullptr;
					
				}
			}
		}
		++itor;
	}
}


void ParticleEmitter::update(float dt) {
	//CC_PROFILER_START_CATEGORY(kProfilerCategoryParticles, "NEW ParticleSystem - update");
	
	if (!this->runningLayer) {
		this->runningLayer = this;
		while (true) {
			if (this->runningLayer->getParent() && this->runningLayer->getParent()->isRunning()) {
				this->runningLayer = this->runningLayer->getParent();
			}
			else {
				break;
			}
		}
		this->addRender();
	}
	
	

	{
		auto itor = childrenParMap.begin();
		while (itor != childrenParMap.end()) {
			auto cPar = (*itor).second;
			if (cPar->_renderer) {
				cPar->_renderer->update(dt);
			}

			Vec2 emitterPos = this->convertToWorldSpace(Vec2::ZERO);
			int parIndex = 0;
			while (parIndex < cPar->_particleCount) {
				auto emitterPar = cPar->_emitter[parIndex];

				emitterPar->pro.timeToLive -= dt;

				if (emitterPar->pro.timeToLive > 0) {
					UpdateHelper::instance->updateParticleMove(emitterPar->pro, dt);
					if (cPar->_positionType == positionType::RELATIVE) {
						emitterPar->par->setPosition(emitterPar->pro.pos);
					}
					else if (cPar->_positionType == positionType::FREE) {
						emitterPar->par->setPosition(Vec2(emitterPar->pro.pos.x - emitterPos.x , emitterPar->pro.pos.y - emitterPos.y));
					}
					
					// 更新旋转
					float nowTimePrecent = (emitterPar->pro.live - emitterPar->pro.timeToLive) / emitterPar->pro.live * 100;
					float rotation = emitterPar->pro.rotation.getParticleVarietyValue(nowTimePrecent);
					if (emitterPar->pro.rotation.pType == particlePropertyType::constValue) {
						// 旋转速度
						float rotationSpeed = emitterPar->pro.rotationSpeed.getParticleVarietyValue(nowTimePrecent);
						emitterPar->pro.rotation.constValue += rotationSpeed * dt;
					}

					emitterPar->par->setRotation(emitterPar->par->getParent()->getRotation() + emitterPar->pro.rotation.constValue);

					parIndex++;
				}
				else {
					emitterPar->par->unscheduleUpdate();
					emitterPar->par->setVisible(false);

					if (cPar->_positionType == positionType::FREE) {
						emitterPar->par->setPosition(Vec2(emitterPar->pro.pos.x - emitterPos.x, emitterPar->pro.pos.y - emitterPos.y));
					}
					emitterPar->par->releaseRender();
					
					emitterPar->par->resetSystem();

					auto tem = cPar->_emitter[parIndex];
					cPar->_emitter[parIndex] = cPar->_emitter[cPar->_particleCount-1];
					cPar->_emitter[cPar->_particleCount - 1] = tem;

					cPar->_particleCount--;
				}
			}

			itor++;
		}
	}
	
	if (!_isActive) {
		if (_isAutoRemoveOnFinish) {
			this->unscheduleUpdate();
			if (this->getParent()) {
				this->removeFromParent();
			}
		}
		return;
	}
	
	// 更新所有的发射属性
	bool isAllFireProNotActive = true;


	for (int i = 0; i < fireProVec.size(); ++i) {
		//float testTime = getNowTime();
		UpdateHelper::instance->updateFirePro(this, *(fireProVec[i]), *this->getChildrenParById(fireProVec[i]->_id), dt);
		
		//float testTime2 = getNowTime();
		//CCLOG("-=-=-=-=-=-=- debug time:%f", (testTime2 - testTime));
		if (fireProVec[i]->_isActive == true) {
			isAllFireProNotActive = false;
		}
	}

	if (this->getParent()) {
		this->setRotation(this->getParent()->getRotation());
	}

	// 如果所有的发射属性都TM玩完了，这个发射器也玩完了
	if (isAllFireProNotActive ) {
		_isActive = false;
		if (!ParticleEmitter::isUiEditorModel) {
			this->worldPos = this->convertToWorldSpace(Vec2(0, 0));
			this->getFatherScale();

			this->releaseRender();   // 先清理render
			this->clearData();       // 清理数据
			if (_isAutoRemoveOnFinish) {
				this->unscheduleUpdate();
				if (this->getParent()) {
					this->removeFromParent();
				}
			}
		}
	}

	
	//CC_PROFILER_START_CATEGORY(kProfilerCategoryParticles, "NEW ParticleSystem - update");
}

void ParticleEmitter::stopSystem() {
	_isActive = false;
	//firePro._elapsed = firePro._duration;
	//firePro._emitCounter = 0;
}
void ParticleEmitter::resetSystem() {
	_isActive = true;


	{
		auto itor = fireProVec.begin();
		while (itor != fireProVec.end()) {
			(*itor)->resetData();
			itor++;
		}
	}
	{
		auto itor = childrenParMap.begin();
		while (itor != childrenParMap.end()) {
			(*itor).second->resetData();
			itor++;
		}
	}

	//firePro._elapsed = 0;
	//_renderer->stopAllParticles();
	//firePro._isDoDelayTime = false;
	//firePro._isDoPreFire = false;
	//firePro._emitCounter = 0;
}

bool ParticleEmitter::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator) {
	auto itor = fireProVec.begin();
	while (itor != fireProVec.end()) {
		m_rapidjson::Value cObject(m_rapidjson::kObjectType);

		(*itor)->writeJsonData((m_rapidjson::Document&)cObject, allocator);

		object.PushBack(cObject, allocator);
		itor++;
	}

	return true;
}
void ParticleEmitter::readJsonData(m_rapidjson::Document& doc) {
	//this->clearData();
	this->runningLayer = nullptr;

	/////
	if (doc.IsArray()) {
		m_rapidjson::Value& array = doc;
		for (int i = 0; i < array.Size(); i++) {

			std::string str = array[i]["parType"].GetString();
			parType ptype = parType::render;;
			if (str == "render") {
				ptype = parType::render;
			}
			else if (str == "emitter") {
				ptype = parType::emitter;
			}
			auto emitterFile = array[i]["emitterFileName"].GetString();

			int id = -1;
			if (array[i].HasMember("id")) {
				id = array[i]["id"].GetInt();
			}

			int maxParticleNum = 0;
			if (array[i].HasMember("maxParticleNum")) {
				maxParticleNum = array[i]["maxParticleNum"].GetInt();
			}

			auto firePro = this->addOneFirePro(id , ptype, emitterFile);
			firePro->readJsonData((m_rapidjson::Document&)array[i]);

			
		}

		//this->addRender();
	}

	this->refreshZorder();
}

//***********************************************************************************---- 结构体的读写文件 ----*****************************************************************

// 写数据到json文件
bool emitterFirePro::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator) {
	// id
	object.AddMember("id", _id, allocator);
	
	object.AddMember("tagName", _tagName.c_str(), allocator);
	object.AddMember("localZorder", _localZorder, allocator);

	if (_parType == parType::render) {
		object.AddMember("parType", "render", allocator);
	}
	else if (_parType == parType::emitter) {
		object.AddMember("parType", "emitter", allocator);
	}
	object.AddMember("emitterFileName", _emitterFileName.c_str(), allocator);
	
	// 纹理
	object.AddMember("texName", _texName.c_str(), allocator);
	// 锚点
	m_rapidjson::Value texAnchorPointObject(m_rapidjson::kObjectType);
	texAnchorPointObject.AddMember("x" , _texAnchorPoint.x , allocator);
	texAnchorPointObject.AddMember("y" , _texAnchorPoint.y, allocator);
	object.AddMember("texAnchorPoint", texAnchorPointObject, allocator);
	
	// 最大粒子数量
	object.AddMember("maxParticleNum", _maxParticleNum, allocator);
	// 粒子的运动模式
	if (_positionType == positionType::FREE) {
		object.AddMember("positionType", "free", allocator);
	}
	else if (_positionType == positionType::RELATIVE) {
		object.AddMember("positionType", "relative", allocator);
	}
	// 混合模式
	object.AddMember("sourceBlend", _sourceBlend, allocator);
	object.AddMember("destBlend", _destBlend, allocator);
	// 运动的角度类型
	if (_angleType == fireAngleType::local) {
		object.AddMember("angleType", "local", allocator);
	}
	else if (_angleType == fireAngleType::global) {
		object.AddMember("angleType", "global", allocator);
	}
	//发射速率
	object.AddMember("emissionRate", _emissionRate , allocator);
	// 粒子发射的周期
	object.AddMember("duration", _duration, allocator);
	// 是否循环发射
	object.AddMember("isLoop", _isLoop, allocator);
	// 是否锁定旋转到移动角度上
	object.AddMember("isLockRotationToMoveAngle", _isLockRotationToMoveAngle, allocator);

	// 预发射几个周期的粒子
	object.AddMember("preFireDuration", _preFireDuration, allocator);
	// 发射开始的延迟
	object.AddMember("delayTime", _delayTime, allocator);

	_fireArea.writeJsonData(object, allocator , "fireArea");

	_tailPro.writeJsonData(object, allocator, "tailPro");

	_life.writeJsonData(object, allocator , "life");
	_startMoveSpeed.writeJsonData(object, allocator , "startMoveSpeed");
	_startMoveAcc.writeJsonData(object, allocator, "startMoveAcc");
	_startMoveAngle.writeJsonData(object, allocator, "startMoveAngle");
	_startMoveAngleSpeed.writeJsonData(object, allocator, "startMoveAngleSpeed");
	_startGravityX.writeJsonData(object, allocator, "startGravityX");
	_startGravityY.writeJsonData(object, allocator, "startGravityY");
	_startSize.writeJsonData(object, allocator, "startSize");
	_startRotation.writeJsonData(object, allocator, "startRotation");
	_startRotationSpeed.writeJsonData(object, allocator, "startRotationSpeed");
	_startSkewX.writeJsonData(object, allocator, "startSkewX");
	_startSkewXSpeed.writeJsonData(object, allocator, "startSkewXSpeed");
	_startSkewY.writeJsonData(object, allocator, "startSkewY");
	_startSkewYSpeed.writeJsonData(object, allocator, "startSkewYSpeed");
	_startAlpha.writeJsonData(object, allocator, "startAlpha");
	_startColor.writeJsonData(object, allocator, "startColor");
	//-------
	_moveSpeedOfLife.writeJsonData(object, allocator, "moveSpeedOfLife");
	_moveAccOfLife.writeJsonData(object, allocator, "moveAccOfLife");
	_moveAngleOfLife.writeJsonData(object, allocator, "moveAngleOfLife");
	_moveAngleSpeedOfLife.writeJsonData(object, allocator, "moveAngleSpeedOfLife");
	_gravityXOfLife.writeJsonData(object, allocator, "gravityXOfLife");
	_gravityYOfLife.writeJsonData(object, allocator, "gravityYOfLife");
	_sizeOfLife.writeJsonData(object, allocator, "sizeOfLife");
	_rotationOfLife.writeJsonData(object, allocator, "rotationOfLife");
	_rotationSpeedOfLife.writeJsonData(object, allocator, "rotationSpeedOfLife");
	_skewXOfLife.writeJsonData(object, allocator, "skewXOfLife");
	_skewXSpeedOfLife.writeJsonData(object, allocator, "skewXSpeedOfLife");
	_skewYOfLife.writeJsonData(object, allocator, "skewYOfLife");
	_skewYSpeedOfLife.writeJsonData(object, allocator, "skewYSpeedOfLife");
	_alphaOfLife.writeJsonData(object, allocator, "alphaOfLife");
	_colorOfLife.writeJsonData(object, allocator, "colorOfLife");

	return true;
}

void emitterFirePro::readJsonData(m_rapidjson::Document& doc) {
	if (doc.HasMember("id")) {
		_id = doc["id"].GetInt();
	}
	
	if (doc.HasMember("tagName")) {
		_tagName = doc["tagName"].GetString();
	}
	if (doc.HasMember("localZorder")) {
		_localZorder = doc["localZorder"].GetInt();
	}
	if (doc.HasMember("parType")) {
		std::string str = doc["parType"].GetString();
		if (str == "render") {
			_parType = parType::render;
		}
		else if (str == "emitter") {
			_parType = parType::emitter;
		}
	}
	if (doc.HasMember("emitterFileName")) {
		_emitterFileName = doc["emitterFileName"].GetString();
		//_emitterFileName = _emitterFileName;
	}

	if (doc.HasMember("texName")) { 
		_texName = doc["texName"].GetString();

		float start = _texName.rfind("\/", _texName.size());
		if (start > -1) {
			std::string name = _texName.substr(start + 1, _texName.size());
			_texName = name;
		}

		_texName = ParticleEmitter::texturePath + _texName;
	}
	if (doc.HasMember("texAnchorPoint")) {
		_texAnchorPoint.x = doc["texAnchorPoint"]["x"].GetDouble();
		_texAnchorPoint.y = doc["texAnchorPoint"]["y"].GetDouble();
	}
	if (doc.HasMember("maxParticleNum")) {
		_maxParticleNum = doc["maxParticleNum"].GetInt();
	}
	if (doc.HasMember("positionType")) {
		std::string positionTypeStr = doc["positionType"].GetString();
		if (positionTypeStr == "free") {
			_positionType = positionType::FREE;
		}
		else if (positionTypeStr == "relative") {
			_positionType = positionType::RELATIVE;
		}
	}
	if (doc.HasMember("sourceBlend")) {
		_sourceBlend = doc["sourceBlend"].GetInt();
	}
	if (doc.HasMember("destBlend")) {
		_destBlend = doc["destBlend"].GetInt();
	}
	if (doc.HasMember("angleType")) {
		std::string angleTypeStr = doc["angleType"].GetString();
		if (angleTypeStr == "local") {
			_angleType = fireAngleType::local;
		}
		else if (angleTypeStr == "global") {
			_angleType = fireAngleType::global;
		}
	}
	if (doc.HasMember("emissionRate")) {
		_emissionRate = doc["emissionRate"].GetDouble();
	}
	if (doc.HasMember("duration")) {
		_duration = doc["duration"].GetDouble();
	}
	if (doc.HasMember("isLoop")) {
		_isLoop = doc["isLoop"].GetBool();
	}
	if (doc.HasMember("isLockRotationToMoveAngle")) {
		_isLockRotationToMoveAngle = doc["isLockRotationToMoveAngle"].GetBool();
	}
	if (doc.HasMember("preFireDuration")) {
		_preFireDuration = doc["preFireDuration"].GetDouble();
	}
	if (doc.HasMember("delayTime")) {
		_delayTime = doc["delayTime"].GetDouble();
	}

	_fireArea.readJsonData(doc, "fireArea");

	_tailPro.readJsonData(doc, "tailPro");

	_life.readJsonData(doc, "life");
	_startMoveSpeed.readJsonData(doc, "startMoveSpeed");
	_startMoveAcc.readJsonData(doc, "startMoveAcc");
	_startMoveAngle.readJsonData(doc, "startMoveAngle");
	_startMoveAngleSpeed.readJsonData(doc, "startMoveAngleSpeed");
	_startGravityX.readJsonData(doc, "startGravityX");
	_startGravityY.readJsonData(doc, "startGravityY");
	_startSize.readJsonData(doc, "startSize");
	_startRotation.readJsonData(doc, "startRotation");
	_startRotationSpeed.readJsonData(doc, "startRotationSpeed");
	_startSkewX.readJsonData(doc, "startSkewX");
	_startSkewXSpeed.readJsonData(doc, "startSkewXSpeed");
	_startSkewY.readJsonData(doc, "startSkewY");
	_startSkewYSpeed.readJsonData(doc, "startSkewYSpeed");
	_startAlpha.readJsonData(doc, "startAlpha");
	_startColor.readJsonData(doc, "startColor");
	//-------
	_moveSpeedOfLife.readJsonData(doc, "moveSpeedOfLife");
	_moveAccOfLife.readJsonData(doc, "moveAccOfLife");
	_moveAngleOfLife.readJsonData(doc, "moveAngleOfLife");
	_moveAngleSpeedOfLife.readJsonData(doc, "moveAngleSpeedOfLife");
	_gravityXOfLife.readJsonData(doc, "gravityXOfLife");
	_gravityYOfLife.readJsonData(doc, "gravityYOfLife");
	_sizeOfLife.readJsonData(doc, "sizeOfLife");
	_rotationOfLife.readJsonData(doc, "rotationOfLife");
	_rotationSpeedOfLife.readJsonData(doc, "rotationSpeedOfLife");
	_skewXOfLife.readJsonData(doc, "skewXOfLife");
	_skewXSpeedOfLife.readJsonData(doc, "skewXSpeedOfLife");
	_skewYOfLife.readJsonData(doc, "skewYOfLife");
	_skewYSpeedOfLife.readJsonData(doc, "skewYSpeedOfLife");
	_alphaOfLife.readJsonData(doc, "alphaOfLife");
	_colorOfLife.readJsonData(doc, "colorOfLife");

}
////---------------------------------------------------------------------------------------------------------------------------------------

void tailPro::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator, char* nameKey) {
	m_rapidjson::Value cObject(m_rapidjson::kObjectType);

	cObject.AddMember("isActive", isActive, allocator);
	cObject.AddMember("tailName", tailName.c_str(), allocator);
	cObject.AddMember("fade", fade, allocator);
	cObject.AddMember("minSeg", minSeg, allocator);
	cObject.AddMember("stroke", stroke, allocator);

	m_rapidjson::Value colorObj(m_rapidjson::kObjectType);
	colorObj.AddMember("r", color.r, allocator);
	colorObj.AddMember("g", color.g, allocator);
	colorObj.AddMember("b", color.b, allocator);

	cObject.AddMember("color", colorObj, allocator);

	object.AddMember(nameKey, cObject, allocator);
}

void tailPro::readJsonData(m_rapidjson::Document& doc, char* nameKey) {
	if (doc.HasMember(nameKey)) {
		if (doc[nameKey].IsObject()) {
			m_rapidjson::Value& object = doc[nameKey];
			if (object.HasMember("isActive")) {
				isActive = object["isActive"].GetBool();
			}
			if (object.HasMember("tailName")) {
				tailName = object["tailName"].GetString();
			}
			if (object.HasMember("fade")) {
				fade = object["fade"].GetDouble();
			}
			if (object.HasMember("minSeg")) {
				minSeg = object["minSeg"].GetDouble();
			}
			if (object.HasMember("stroke")) {
				stroke = object["stroke"].GetDouble();
			}
			if (object.HasMember("color")) {
				color = Color3B(object["color"]["r"].GetDouble(), object["color"]["g"].GetDouble(), object["color"]["b"].GetDouble());
			}
		}
	}
}

////---------------------------------------------------------------------------------------------------------------------------------------
void varietyFireAreaValue::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator , char* nameKey) {
	m_rapidjson::Value cObject(m_rapidjson::kObjectType);

	if (fAreaType == fireAreaType::rect) {
		cObject.AddMember("fAreaType", "rect", allocator);

		m_rapidjson::Value inRectObject(m_rapidjson::kObjectType);
		inRectObject.AddMember("width", inRect.width, allocator);
		inRectObject.AddMember("height", inRect.height, allocator);
		cObject.AddMember("inRect", inRectObject, allocator);

		m_rapidjson::Value outRectObject(m_rapidjson::kObjectType);
		outRectObject.AddMember("width", outRect.width, allocator);
		outRectObject.AddMember("height", outRect.height, allocator);
		cObject.AddMember("outRect", outRectObject, allocator);
	}
	else if (fAreaType == fireAreaType::circle) {
		cObject.AddMember("fAreaType", "circle", allocator);
		cObject.AddMember("inCircleRadius", inCircleRadius , allocator);
		cObject.AddMember("outCircleRadius", outCircleRadius , allocator);
	}
	else if (fAreaType == fireAreaType::polygon) {
		cObject.AddMember("fAreaType", "polygon", allocator);
		// 创建一个数组保存多边形的点
		m_rapidjson::Value pPointsArray(m_rapidjson::kArrayType);

		auto itor = polygonPoints.begin();
		while (itor != polygonPoints.end()) {
			m_rapidjson::Value pPointObject(m_rapidjson::kObjectType);

			pPointObject.AddMember("x" , (*itor).x, allocator);
			pPointObject.AddMember("y" , (*itor).y, allocator);

			pPointsArray.PushBack(pPointObject, allocator);
			itor++;
		}

		cObject.AddMember("polygonPoints", pPointsArray, allocator);

	}
	else if (fAreaType == fireAreaType::lines) {
		cObject.AddMember("fAreaType", "lines", allocator);

		// 创建一个数组保存 自定义线条 的点
		m_rapidjson::Value lPointsArray(m_rapidjson::kArrayType);

		auto itor = linePoints.begin();
		while (itor != linePoints.end()) {
			m_rapidjson::Value lPointObject(m_rapidjson::kObjectType);

			lPointObject.AddMember("x", (*itor).x, allocator);
			lPointObject.AddMember("y", (*itor).y, allocator);

			lPointsArray.PushBack(lPointObject, allocator);
			itor++;
		}

		cObject.AddMember("linePoints", lPointsArray, allocator);
	}

	cObject.AddMember("isEdgeFire", isEdgeFire, allocator);
	cObject.AddMember("edgeFireWidth", edgeFireWidth, allocator);

	object.AddMember ( nameKey , cObject , allocator);
}

void varietyFireAreaValue::readJsonData(m_rapidjson::Document& doc, char* nameKey) {
	polygonPoints.clear();
	isChangePolygonToTriangleVec = false;
	linePoints.clear();

	if (doc.HasMember(nameKey)) {
		if (doc[nameKey].IsObject()) {
			m_rapidjson::Value& object = doc[nameKey];
			std::string typeStr = object["fAreaType"].GetString();
			if (typeStr == "rect") {
				fAreaType = fireAreaType::rect;

				inRect.width = object["inRect"]["width"].GetDouble();
				inRect.height = object["inRect"]["height"].GetDouble();
				outRect.width = object["outRect"]["width"].GetDouble();
				outRect.height = object["outRect"]["height"].GetDouble();

			}
			else if (typeStr == "circle") {
				fAreaType = fireAreaType::circle;
				inCircleRadius = object["inCircleRadius"].GetDouble();
				outCircleRadius = object["outCircleRadius"].GetDouble();

			}
			else if (typeStr == "polygon") {
				fAreaType = fireAreaType::polygon;
				
				m_rapidjson::Value& array = object["polygonPoints"];
				for (int i = 0; i < array.Size(); ++i) {
					m_rapidjson::Value& item = array[i];
					float x = item["x"].GetDouble();
					float y = item["y"].GetDouble();

					polygonPoints.push_back(Vec2( x,y ));
				}

			}
			else if (typeStr == "lines") {
				fAreaType = fireAreaType::lines;
				
				m_rapidjson::Value& array = object["linePoints"];
				for (int i = 0; i < array.Size(); ++i) {
					m_rapidjson::Value& item = array[i];
					float x = item["x"].GetDouble();
					float y = item["y"].GetDouble();

					linePoints.push_back(Vec2(x, y));
				}
			}

			if (object.HasMember("isEdgeFire")) {
				isEdgeFire = object["isEdgeFire"].GetBool();
			}
			if (object.HasMember("edgeFireWidth")) {
				edgeFireWidth = object["edgeFireWidth"].GetDouble();
			}

		}
	}
}


////---------------------------------------------------------------------------------------------------------------------------------------
void emitterVarietyValue::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator, char* nameKey) {
	m_rapidjson::Value cObject(m_rapidjson::kObjectType);

	if (pType == emitterPropertyType::oneConstant) {
		cObject.AddMember("pType", "oneConstant", allocator);
		cObject.AddMember("constValue", constValue, allocator);
	}
	else if (pType == emitterPropertyType::randBetweenTwoConst) {
		cObject.AddMember("pType", "randBetweenTwoConst", allocator);
		cObject.AddMember("randConst1", randConst1, allocator);
		cObject.AddMember("randConst2", randConst2, allocator);
	}
	else if (pType == emitterPropertyType::moreConstant) {
		cObject.AddMember("pType", "moreConstant", allocator);

		// 创建一个数组
		m_rapidjson::Value moreConstantArray(m_rapidjson::kArrayType);

		auto itor = constValues.begin();
		while (itor != constValues.end()) {
			moreConstantArray.PushBack((*itor), allocator);
			itor++;
		}

		cObject.AddMember("constValues", moreConstantArray, allocator);
	}
	else if (pType == emitterPropertyType::curve) {
		cObject.AddMember("pType", "curve", allocator);

		if (curvePoints.size() <= 0) {
			return;
		}

		// 创建一个数组
		m_rapidjson::Value curvePointsArray(m_rapidjson::kArrayType);
		auto itor = curvePoints.begin();
		while (itor != curvePoints.end()) {
			
			m_rapidjson::Value curvePointObject(m_rapidjson::kObjectType);

			curvePointObject.AddMember("x", (*itor).x, allocator);
			curvePointObject.AddMember("y", (*itor).y, allocator);
			curvePointObject.AddMember("z", (*itor).z, allocator);

			curvePointsArray.PushBack(curvePointObject, allocator);
			itor++;
		}

		cObject.AddMember("curvePoints", curvePointsArray, allocator);
	}
	else if (pType == emitterPropertyType::none) {
		return;
	}

	object.AddMember(nameKey, cObject, allocator);
}

void emitterVarietyValue::readJsonData(m_rapidjson::Document& doc, char* nameKey) {
	pType = emitterPropertyType::oneConstant;
	constValues.clear();
	curvePoints.clear();
	isSetCurveKB = false;

	if (doc.HasMember(nameKey)) {
		if (doc[nameKey].IsObject()) {
			m_rapidjson::Value& object = doc[nameKey];
			std::string typeStr = object["pType"].GetString();
			if (typeStr == "oneConstant") {
				pType = emitterPropertyType::oneConstant;
				constValue = object["constValue"].GetDouble();
			}
			else if (typeStr == "randBetweenTwoConst") {
				pType = emitterPropertyType::randBetweenTwoConst;
				randConst1 = object["randConst1"].GetDouble();
				randConst2 = object["randConst2"].GetDouble();
			}
			else if (typeStr == "moreConstant") {
				pType = emitterPropertyType::moreConstant;
				constValues.clear();

				m_rapidjson::Value& array = object["constValues"];
				for (int i = 0; i < array.Size(); ++i) {
					constValues.push_back(array[i].GetDouble());
				}
			}
			else if (typeStr == "curve") {
				pType = emitterPropertyType::curve;
				curvePoints.clear();

				m_rapidjson::Value& array = object["curvePoints"];
				for (int i = 0; i < array.Size(); ++i) {
					m_rapidjson::Value& item = array[i];
					float x = item["x"].GetDouble();
					float y = item["y"].GetDouble();
					float z = item["z"].GetDouble();

					curvePoints.push_back(Vec3(x,y,z));
				}
			}
		}
	}
}

////---------------------------------------------------------------------------------------------------------------------------------------
void emitterColorValue::writeJsonData(m_rapidjson::Document& object, m_rapidjson::Document::AllocatorType& allocator, char* nameKey) {
	m_rapidjson::Value cObject(m_rapidjson::kObjectType);

	if (pType == emitterPropertyType::oneConstant) {
		cObject.AddMember("pType", "oneConstant", allocator);
		
		m_rapidjson::Value constColorObject(m_rapidjson::kObjectType);
		constColorObject.AddMember("r", constColor.r, allocator);
		constColorObject.AddMember("g", constColor.g, allocator);
		constColorObject.AddMember("b", constColor.b, allocator);

		cObject.AddMember("constColor" , constColorObject, allocator);
	}
	else if (pType == emitterPropertyType::randBetweenTwoConst) {
		cObject.AddMember("pType", "randBetweenTwoConst", allocator);
		
		m_rapidjson::Value randColorObject1(m_rapidjson::kObjectType);
		randColorObject1.AddMember("r", randColor1.r, allocator);
		randColorObject1.AddMember("g", randColor1.g, allocator);
		randColorObject1.AddMember("b", randColor1.b, allocator);
		cObject.AddMember("randColor1", randColorObject1, allocator);

		m_rapidjson::Value randColorObject2(m_rapidjson::kObjectType);
		randColorObject2.AddMember("r", randColor2.r, allocator);
		randColorObject2.AddMember("g", randColor2.g, allocator);
		randColorObject2.AddMember("b", randColor2.b, allocator);
		cObject.AddMember("randColor2", randColorObject2, allocator);

	}
	else if (pType == emitterPropertyType::moreConstant) {
		cObject.AddMember("pType", "moreConstant", allocator);

		m_rapidjson::Value constColorsArray(m_rapidjson::kArrayType);
		
		auto itor = constColors.begin();
		while (itor != constColors.end()) {
			m_rapidjson::Value colorsObject(m_rapidjson::kObjectType);
			colorsObject.AddMember("r" , (*itor).r, allocator);
			colorsObject.AddMember("g" , (*itor).g, allocator);
			colorsObject.AddMember("b" , (*itor).b, allocator);

			constColorsArray.PushBack(colorsObject, allocator);
			itor++;
		}

		cObject.AddMember("constColors", constColorsArray, allocator);
	}
	else if (pType == emitterPropertyType::curve) {
		cObject.AddMember("pType", "curve", allocator);

		if (curveColors.size() <= 0) {
			return;
		}
		m_rapidjson::Value curveColorsArray(m_rapidjson::kArrayType);
		auto itor = curveColors.begin();
		while (itor != curveColors.end()) {
			m_rapidjson::Value colorCurvePointObject(m_rapidjson::kObjectType);

			colorCurvePointObject.AddMember("x", (*itor).x, allocator);

			m_rapidjson::Value colorYObject(m_rapidjson::kObjectType);
			colorYObject.AddMember("r", (*itor).colorY.r, allocator);
			colorYObject.AddMember("g", (*itor).colorY.g, allocator);
			colorYObject.AddMember("b", (*itor).colorY.b, allocator);
			colorCurvePointObject.AddMember("colorY", colorYObject, allocator);

			m_rapidjson::Value colorRandObject(m_rapidjson::kObjectType);
			colorRandObject.AddMember("x", (*itor).colorRand.x, allocator);
			colorRandObject.AddMember("y", (*itor).colorRand.y, allocator);
			colorRandObject.AddMember("z", (*itor).colorRand.z, allocator);
			colorCurvePointObject.AddMember("colorRand", colorRandObject, allocator);

			curveColorsArray.PushBack(colorCurvePointObject, allocator);
			itor++;
		}

		cObject.AddMember("curveColors", curveColorsArray, allocator);
	}
	else if (pType == emitterPropertyType::none) {
		return;
	}

	object.AddMember(nameKey, cObject, allocator);
}

void emitterColorValue::readJsonData(m_rapidjson::Document& doc, char* nameKey) {
	pType = emitterPropertyType::oneConstant;
	constColors.clear();
	curveColors.clear();

	if (doc.HasMember(nameKey)) {
		if (doc[nameKey].IsObject()) {
			m_rapidjson::Value& object = doc[nameKey];
			std::string typeStr = object["pType"].GetString();

			if (typeStr == "oneConstant") {
				pType = emitterPropertyType::oneConstant;
				
				m_rapidjson::Value& item = object["constColor"];
				float r = item["r"].GetDouble();
				float g = item["g"].GetDouble();
				float b = item["b"].GetDouble();

				constColor = Color3B(r,g,b);
			}
			else if (typeStr == "randBetweenTwoConst") {
				pType = emitterPropertyType::randBetweenTwoConst;
				
				m_rapidjson::Value& item1 = object["randColor1"];
				float r1 = item1["r"].GetDouble();
				float g1 = item1["g"].GetDouble();
				float b1 = item1["b"].GetDouble();
				randColor1 = Color3B(r1, g1, b1);

				m_rapidjson::Value& item2 = object["randColor2"];
				float r2 = item2["r"].GetDouble();
				float g2 = item2["g"].GetDouble();
				float b2 = item2["b"].GetDouble();
				randColor2 = Color3B(r2, g2, b2);
			}
			else if (typeStr == "moreConstant") {
				pType = emitterPropertyType::moreConstant;
				constColors.clear();

				m_rapidjson::Value& array = object["constColors"];
				for (int i = 0; i < array.Size(); ++i) {
					m_rapidjson::Value& item = array[i];

					float r = item["r"].GetDouble();
					float g = item["g"].GetDouble();
					float b = item["b"].GetDouble();
					constColors.push_back( Color3B(r, g, b));
				}
			}
			else if (typeStr == "curve") {
				pType = emitterPropertyType::curve;
				
				m_rapidjson::Value& array = object["curveColors"];
				for (int i = 0; i < array.Size(); ++i) {
					m_rapidjson::Value& item = array[i];

					float x = item["x"].GetDouble();
					float colorYR = item["colorY"]["r"].GetDouble();
					float colorYG = item["colorY"]["g"].GetDouble();
					float colorYB = item["colorY"]["b"].GetDouble();
					float colorRandX = item["colorRand"]["x"].GetDouble();
					float colorRandY = item["colorRand"]["y"].GetDouble();
					float colorRandZ = item["colorRand"]["z"].GetDouble();

					colorCurvePoint curveColor;
					curveColor.x = x;
					curveColor.colorY = Color3B(colorYR, colorYG, colorYB);
					curveColor.colorRand = Vec3(colorRandX, colorRandY, colorRandZ);
					curveColors.push_back(curveColor);
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////----- 提供给外部的接口
void ParticleEmitter::setFirePro_LocalZOrder(int id, int localZOrder) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_localZorder = localZOrder;
	}

	auto cPar = childrenParMap.find(firePro->_id);
	if (cPar != childrenParMap.end()) {
		if (cPar->second->_renderer)
		{
			cPar->second->_renderer->setLocalZOrder(firePro->_localZorder);
		}
	}
}

void ParticleEmitter::setFirePro_ParType(int id, std::string type) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		if (type == "render") {
			firePro->_parType = parType::render;
		}
		else if (type == "emitter") {
			firePro->_parType = parType::emitter;
		}
	}
}
void ParticleEmitter::setFirePro_EmitterFileName(int id, std::string name) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_emitterFileName = name;
	}
}
void ParticleEmitter::setFirePro_TexName(int id, std::string texName) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_texName = texName;
	}
}
void ParticleEmitter::setFirePro_AnchorPoint(int id, float x, float y) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_texAnchorPoint = Vec2(x , y);
	}
}
void ParticleEmitter::setFirePro_MaxParticleNum(int id, int num) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_maxParticleNum = num;
	}
}

void ParticleEmitter::setFirePro_PositionType(int id, std::string type) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		if (type == "free") {
			firePro->_positionType = positionType::FREE;
		}
		else if (type == "relative") {
			firePro->_positionType = positionType::RELATIVE;
		}
	}
}

void ParticleEmitter::setFirePro_SourceBlend(int id, int sourceBlend) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_sourceBlend = sourceBlend;
	}
}
void ParticleEmitter::setFirePro_DestBlend(int id, int destBlend) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_destBlend = destBlend;
	}
}

void ParticleEmitter::setFirePro_FireAngleType(int id, std::string type) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		if (type == "local") {
			firePro->_angleType = fireAngleType::local;
		}
		else if (type == "global") {
			firePro->_angleType = fireAngleType::global;
		}
	}
}
void ParticleEmitter::setFirePro_emissionRate(int id, float rate) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_emissionRate = rate;
	}
}
void ParticleEmitter::setFirePro_duration(int id, float duration) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_duration = duration;
	}
}
void ParticleEmitter::setFirePro_isLoop(int id, bool loop) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_isLoop = loop;
	}
}

void ParticleEmitter::setFirePro_isLockRotationToMoveAngle(int id, bool isLock) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_isLockRotationToMoveAngle = isLock;
	}
}


void ParticleEmitter::setFirePro_preFireDuration(int id, float preFire) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_preFireDuration = preFire;
	}
}

void ParticleEmitter::setFirePro_delayTime(int id, float delay) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_delayTime = delay;
	}
}

void ParticleEmitter::setFirePro_IsFlowCircleRadius(int id, bool isFlow) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_isFlowCircleRadius = isFlow;
	}
}

// -- 发射区域
void ParticleEmitter::setFirePro_fireArea(int id, float inRectWidth, float inRectHeight, float outRectWidth, float outRectHeight) { // rect
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_fireArea.fAreaType = fireAreaType::rect;
		firePro->_fireArea.inRect = Size(inRectWidth , inRectHeight);
		firePro->_fireArea.outRect = Size(outRectWidth, outRectHeight);
	}
}
void ParticleEmitter::setFirePro_fireArea(int id, float inCirecleRadius, float outCircleRadius) { // circle
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_fireArea.fAreaType = fireAreaType::circle;
		firePro->_fireArea.inCircleRadius = inCirecleRadius;
		firePro->_fireArea.outCircleRadius = outCircleRadius;
	}
}

void ParticleEmitter::setFirePro_fireArea_clear(int id) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_fireArea.polygonPoints.clear();
		firePro->_fireArea.linePoints.clear();
		firePro->_fireArea.polygonTriangleVec.clear();
		firePro->_fireArea.polygonLinesDis.clear();
		
		firePro->_fireArea.isChangePolygonToTriangleVec = false;
	}
}

void ParticleEmitter::setFirePro_fireArea_pushPolygonPoint(int id, float posX, float posY) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_fireArea.fAreaType = fireAreaType::polygon;
		firePro->_fireArea.polygonPoints.push_back(Vec2(posX , posY));
	}
}

void ParticleEmitter::setFirePro_fireArea_pushLinePoint(int id, float posX, float posY) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_fireArea.fAreaType = fireAreaType::lines;
		firePro->_fireArea.linePoints.push_back(Vec2(posX, posY));
	}
}

// -- 拖尾
void ParticleEmitter::setFirePro_tailPro_isActive(int id, bool isActive) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_tailPro.isActive = isActive;
	}
}
void ParticleEmitter::setFirePro_tailPro(int id, std::string tailName, float fade, float minSeg, float stroke, float color_r, float color_g, float color_b) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		firePro->_tailPro.tailName = tailName;
		firePro->_tailPro.fade = fade;
		firePro->_tailPro.minSeg = minSeg;
		firePro->_tailPro.stroke = stroke;
		firePro->_tailPro.color = Color3B(color_r, color_g, color_b);
	}
}

emitterVarietyValue* ParticleEmitter::getVarietyValueByType(emitterFirePro* firePro, std::string type) {
	if (type == "life") {
		return &firePro->_life;
	}
	else if (type == "startMoveSpeed") {
		return &firePro->_startMoveSpeed;
	}
	else if (type == "startMoveAcc") {
		return &firePro->_startMoveAcc;
	}
	else if (type == "startMoveAngle") {
		return &firePro->_startMoveAngle;
	}
	else if (type == "startMoveAngleSpeed") {
		return &firePro->_startMoveAngleSpeed;
	}
	else if (type == "startGravityX") {
		return &firePro->_startGravityX;
	}
	else if (type == "startGravityY") {
		return &firePro->_startGravityY;
	}
	else if (type == "startSize") {
		return &firePro->_startSize;
	}
	else if (type == "startRotation") {
		return &firePro->_startRotation;
	}
	else if (type == "startRotationSpeed") {
		return &firePro->_startRotationSpeed;
	}
	else if (type == "startSkewX") {
		return &firePro->_startSkewX;
	}
	else if (type == "startSkewXSpeed") {
		return &firePro->_startSkewXSpeed;
	}
	else if (type == "startSkewY") {
		return &firePro->_startSkewY;
	}
	else if (type == "startSkewYSpeed") {
		return &firePro->_startSkewYSpeed;
	}
	else if (type == "startAlpha") {
		return &firePro->_startAlpha;
	}
	else if (type == "moveSpeedOfLife") {
		return &firePro->_moveSpeedOfLife;
	}
	else if (type == "moveAccOfLife") {
		return &firePro->_moveAccOfLife;
	}
	else if (type == "moveAngleOfLife") {
		return &firePro->_moveAngleOfLife;
	}
	else if (type == "moveAngleSpeedOfLife") {
		return &firePro->_moveAngleSpeedOfLife;
	}
	else if (type == "gravityXOfLife") {
		return &firePro->_gravityXOfLife;
	}
	else if (type == "gravityYOfLife") {
		return &firePro->_gravityYOfLife;
	}
	else if (type == "sizeOfLife") {
		return &firePro->_sizeOfLife;
	}
	else if (type == "rotationOfLife") {
		return &firePro->_rotationOfLife;
	}
	else if (type == "rotationSpeedOfLife") {
		return &firePro->_rotationSpeedOfLife;
	}
	else if (type == "skewXOfLife") {
		return &firePro->_skewXOfLife;
	}
	else if (type == "skewXSpeedOfLife") {
		return &firePro->_skewXSpeedOfLife;
	}
	else if (type == "skewYOfLife") {
		return &firePro->_skewYOfLife;
	}
	else if (type == "skewYSpeedOfLife") {
		return &firePro->_skewYSpeedOfLife;
	}
	else if (type == "alphaOfLife") {
		return &firePro->_alphaOfLife;
	}
	return nullptr;
}

// 其他属性
void ParticleEmitter::setFirePro_varietyValue(int id, std::string valueType, float value) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		auto vValue = getVarietyValueByType(firePro, valueType);
		if (vValue) {
			vValue->pType == emitterPropertyType::oneConstant;
			vValue->constValue = value;
		}
	}
}

void ParticleEmitter::setFirePro_varietyValue(int id, std::string valueType, float randvalue1, float randvalue2) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		auto vValue = getVarietyValueByType(firePro, valueType);
		if (vValue) {
			vValue->pType == emitterPropertyType::randBetweenTwoConst;
			vValue->randConst1 = randvalue1;
			vValue->randConst2 = randvalue2;
		}
	}
}

void ParticleEmitter::setFirePro_varietyValue_clear(int id, std::string valueType) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		auto vValue = getVarietyValueByType(firePro, valueType);
		if (vValue) {
			vValue->constValues.clear();
			vValue->curvePoints.clear();
		}
	}

}

void ParticleEmitter::setFirepro_varietyValue_pushMoreValue(int id, std::string valueType, float value) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		auto vValue = getVarietyValueByType(firePro, valueType);
		if (vValue) {
			vValue->pType == emitterPropertyType::moreConstant;
			vValue->constValues.push_back(value);
		}
	}

}

void ParticleEmitter::setFirePro_varietyValue_pushCurveValue(int id, std::string valueType , float x, float value , float randValue) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		auto vValue = getVarietyValueByType(firePro, valueType);
		if (vValue) {
			vValue->pType == emitterPropertyType::curve;
			
			float realX = x;
			if (valueType == "moveSpeedOfLife" || valueType == "moveAccOfLife" || valueType == "moveAngleOfLife" || valueType == "moveAngleSpeedOfLife" ||
				valueType == "gravityXOfLife" || valueType == "gravityYOfLife" || valueType == "sizeOfLife" || valueType == "rotationOfLife" ||
				valueType == "rotationSpeedOfLife" || valueType == "skewXOfLife" || valueType == "skewXSpeedOfLife" || valueType == "skewYOfLife" ||
				valueType == "skewYSpeedOfLife" || valueType == "alphaOfLife" ) {
				
			}
			else {
				realX /= 100.0;
			}
				

			vValue->curvePoints.push_back(Vec3(realX, value , randValue));
		}
	}

}

//////
void ParticleEmitter::setFirePro_colorValue(int id, std::string valueType, float color_r, float color_g, float color_b) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		emitterColorValue* colorValue = nullptr;
		if (valueType == "startColor") {
			colorValue = &firePro->_startColor;
		}
		else if (valueType == "colorOfLife") {
			colorValue = &firePro->_colorOfLife;
		}

		if (colorValue) {
			colorValue->pType = emitterPropertyType::oneConstant;
			colorValue->constColor = Color3B(color_r, color_g, color_b);
		}

	}
}

void ParticleEmitter::setFirePro_colorValue(int id, std::string valueType, float randcolor1_r, float randcolor1_g, float randcolor1_b, float randcolor2_r, float randcolor2_g, float randcolor2_b) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		emitterColorValue* colorValue = nullptr;
		if (valueType == "startColor") {
			colorValue = &firePro->_startColor;
		}
		else if (valueType == "colorOfLife") {
			colorValue = &firePro->_colorOfLife;
		}

		if (colorValue) {
			colorValue->pType = emitterPropertyType::randBetweenTwoConst;
			colorValue->randColor1 = Color3B(randcolor1_r, randcolor1_g, randcolor1_b);
			colorValue->randColor2 = Color3B(randcolor2_r, randcolor2_g, randcolor2_b);
		}

	}
}

void ParticleEmitter::setFirePro_colorValue_clear(int id, std::string valueType) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		emitterColorValue* colorValue = nullptr;
		if (valueType == "startColor") {
			colorValue = &firePro->_startColor;
		}
		else if (valueType == "colorOfLife") {
			colorValue = &firePro->_colorOfLife;
		}

		if (colorValue) {
			colorValue->constColors.clear();
			colorValue->curveColors.clear();
		}

	}
}

void ParticleEmitter::setFirepro_colorValue_pushMoreValue(int id, std::string valueType, float color_r, float color_g, float color_b) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		emitterColorValue* colorValue = nullptr;
		if (valueType == "startColor") {
			colorValue = &firePro->_startColor;
		}
		else if (valueType == "colorOfLife") {
			colorValue = &firePro->_colorOfLife;
		}

		if (colorValue) {
			colorValue->pType = emitterPropertyType::moreConstant;
			colorValue->constColors.push_back(Color3B(color_r, color_g, color_b));
		}

	}
}

void ParticleEmitter::setFirePro_colorValue_pushCurveValue(int id, std::string valueType, float x, float color_r, float color_g, float color_b, float randcolor_r, float randcolor_g, float randcolor_b) {
	auto firePro = this->getFireProById(id);
	if (firePro) {
		emitterColorValue* colorValue = nullptr;
		if (valueType == "startColor") {
			colorValue = &firePro->_startColor;
		}
		else if (valueType == "colorOfLife") {
			colorValue = &firePro->_colorOfLife;
		}

		if (colorValue) {
			colorValue->pType = emitterPropertyType::curve;

			colorCurvePoint cPoint;
			float targetX = x;
			if (valueType == "startColor") {
				targetX /= 100.0;
			}

			cPoint.x = targetX;
			cPoint.colorY = Color3B(color_r, color_g, color_b);
			cPoint.colorRand = Vec3(randcolor_r,randcolor_g,randcolor_b);

			colorValue->curveColors.push_back(cPoint);
		}

	}
}

void ParticleEmitter::readJsonDataFromFile(std::string filename) {
	//this->setPosition(Vec2::ZERO);
	//CocosApiFactory::getInstance()->setPosition( this , Vec2::ZERO );
	this->readJsonData(FileCenter::getInstance()->readJsonData(filename));

	float start = filename.rfind("\/", filename.size());
	if (start > -1) {
		std::string path = filename.substr(0, start + 1);
		ParticleEmitter::sourcePath = path;
		//CCLOG("-------------------ParticleEmitter::sourcePath :%s", ParticleEmitter::sourcePath);
	}
}

//////////////////////////////////////
//// 接口定义，双方都用的
//
//class IParSprite
//{
//public:
//	virtual void setPosition(Vec2 &vec) = 0;
//};
//
//class IParAction
//{
//public:
//	virtual void setPosition(Vec2 &vec) = 0;
//};
//
//class IParticleFactory
//{
//public:
//	virtual IParSprite * createSprite() = 0;
//	virtual IParAction * createAction() = 0;
//};
//
//
//////////////////////////////////////
//// 类对象实现： 各自实现
//
//
//class CParSprite:public IParSprite
//{
//public:
//	cocos2d::Sprite * _sprite = nullptr;
//	
//	virtual void setPosition(Vec2 &vec)
//	{
//		_sprite->setPosition(vec);
//	}
//};
//
//class IParAction
//{
//public:
//	cocos2d::Action * action = nullptr;
//	virtual void setPosition(Vec2 &vec)
//	{
//		action->setPosition(vec);
//	}
//};
//
//
//class CParticleFactory : public IParticleFactory
//{
//public:
//	virtual IParSprite * createSprite()
//	{
//		auto ret = new CParSprite;
//		ret->_sprite = cocos2d::Sprite::create();
//		return ret;
//	}
//	virtual IParAction * createAction()
//	{
//		auto ret = new cocos2d::Action;
//		ret->action = cocos2d::Action::create();
//		return ret;
//	}
//};
//
//
//
//////////////////////////////////////
//// 库里面实现的函数
//
//void setParFactory(IParticleFactory * factory)
//{
//	g_parFactory = factory;
//}
//
//////////////////////////////////////
//// 库里面使用对象
//
//Sprite * xxx = g_parFactory->createSprite();
//xxx->setPosition()
//
//
//////////////////////////////////////
//// 在外面设置工厂类
//
//setParFactory(new CParticleFactory())

