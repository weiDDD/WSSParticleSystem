#include "ParticleRenderer.h"
#include "ParticleEmitter.h"
#include "UpdateHelper.h"
using namespace pp;

// 渲染是否由本类来渲染，TRUE 就是本类来渲染, false交给cocos
static bool render_by_this_class = false;

int ParticleRenderer::updatePriority = 0;

static size_t vec2xOffset = offsetof(Vec2 , x);
static size_t vec2yOffset = offsetof(Vec2, y);

static long getNowTime() {
	struct timeval now;
	gettimeofday(&now, NULL);
	return now.tv_usec;
}

void particleVarietyValue::refreshPointer() {
	if (curveKB.size() > 0) {
		curveKbFirstPoint = &curveKB[0];
	}
	if (curvePoints.size() > 0) {
		curvePointFirstPoint = &curvePoints[0];
	}
}

float particleVarietyValue::getParticleVarietyValue(float nowTime) {
	if (pType == particlePropertyType::constValue) {
		return constValue;
	}
	else if (pType == particlePropertyType::curve) {
		// 曲线数据
		// 当前的时间
		//float nowTime = (p.live - p.timeToLive) / p.live * 100;  // 当前经过的时间 在全部总生命中的百分比
		nowTime = (nowTime < 0) ? 0 : nowTime;
		nowTime = (nowTime > 100) ? 100 : nowTime;
		// 设置KB
		if (!isSetCurveKB) {
			int kbSize = curveKB.size();
			if (kbSize > 0) {
				curveKB.clear();
				kbSize = 0;
				curveKbFirstPoint = nullptr;
			}
			if (kbSize <= 0) {

				curveKB.reserve(curvePointSize - 1);

				for (int i = 0; i < curvePointSize - 1; ++i) {
					Vec2 left = curvePoints[i];
					Vec2 right = curvePoints[i + 1];

					float k = (right.y - left.y) / ((right.x - left.x));
					float b = left.y - k*left.x;

					curveKB.push_back(Vec2(k, b));
					++kbSize;
				}
			}
			isSetCurveKB = true;

			if (kbSize > 0) {
				curveKbFirstPoint = &curveKB[0];
			}

		}

		//获取曲线数据，如果当前时间百分比 小于最左边的 那么 返回 constAndDelta 的数据；如果大于了最右边的 那么 返回 (n - right) % (right - left)
		if (nowTime < curveLeftPointX) {
			return constValue;
		}
		else {
			float realNowTime = nowTime;
			if (nowTime > curveRightPointX) {
				//如果大于了最右边的
				realNowTime = int(nowTime - curveRightPointX) % int(curveRightPointX - curveLeftPointX) + curveLeftPointX;
			}


			int index = 0;
			Vec2* i = curvePointFirstPoint;
			++i;
			for (; index < curvePointSize - 1; ++i) {
				//float leftPosX = i->x;
				//float leftPosX = *(float*)(i + vec2xOffset);
				if (realNowTime < i->x) {
					Vec2* kbVec = curveKbFirstPoint + index;
					float k = kbVec->x;  // curveKB[index].x;  // 7.1
					float b = kbVec->y;  //curveKB[index].y;  // 3.7
					float realPY = k * realNowTime + b;
					return realPY;
				}
				++index;
			}

		}
	}
	return 0;
}


void particleColorValue::refreshPointer() {
	if (curveColors.size() > 0) {
		curveColorsFirstPtr = &curveColors[0];
	}
}

Color3B particleColorValue::getParticleVarietyValue(float nowTime) {
	if (pType == particlePropertyType::constValue) {

		return constColor;
	}
	else if (pType == particlePropertyType::curve) {

		// 曲线数据
		if (!isSetRealColorY) {
			int size = curveColors.size();
			for (int i = 0; i < size; ++i) {
				colorCurvePoint* curveColor = &curveColors[i];
				curveColor->realColorY.r = curveColor->colorY.r + CCRANDOM_0_1() * 2 * curveColor->colorRand.x - curveColor->colorRand.x;
				curveColor->realColorY.g = curveColor->colorY.g + CCRANDOM_0_1() * 2 * curveColor->colorRand.y - curveColor->colorRand.y;
				curveColor->realColorY.b = curveColor->colorY.b + CCRANDOM_0_1() * 2 * curveColor->colorRand.z - curveColor->colorRand.z;
			}

			isSetRealColorY = true;
		}

		// 当前的时间
		//float nowTime = (p.live - p.timeToLive) / p.live * 100;  // 当前经过的时间 在全部总生命中的百分比
		nowTime = (nowTime < 0) ? 0 : nowTime;
		nowTime = (nowTime > 100) ? 100 : nowTime;

		//获取曲线数据，如果当前时间百分比 小于最左边的 那么 返回 constAndDelta 的数据；如果大于了最右边的 那么 返回 (n - right) % (right - left)
		//float leftX = curveColors[0].x;
		if (nowTime < curveLeftPointX) {
			return constColor;
		}
		else {
			//int size = curveColors.size();

			float realNowTime = nowTime;
			//float rightX = curveColors[curveColorsSize - 1].x;
			if (nowTime > curveRightPointX) {
				//如果大于了最右边的
				realNowTime = int(nowTime - curveRightPointX) % int(curveRightPointX - curveLeftPointX) + curveLeftPointX;
			}

			colorCurvePoint* colorPtr = curveColorsFirstPtr;
			++colorPtr;
			int index = 0;
			for (colorPtr; index < curveColorsSize - 1; ++colorPtr) {
				float rightPosX = colorPtr->x;
				if (realNowTime < rightPosX) {
					float leftPosX = (colorPtr -1)->x;
					Color3B leftColor = (colorPtr -1)->realColorY;
					Color3B rightColor = colorPtr->realColorY;

					float precent = (realNowTime - leftPosX) / (rightPosX - leftPosX);
					return Color3B(leftColor.r + precent * (rightColor.r - leftColor.r), leftColor.g + precent * (rightColor.g - leftColor.g), leftColor.b + precent * (rightColor.b - leftColor.b));

				}
				++index;
			}

		}
		return Color3B::WHITE;
	}
	else {
		return Color3B::WHITE;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////
int ParticleRenderer::maxCacheSize = 300;
int ParticleRenderer::cacheSize = 0;
std::vector<ParticleRenderer*> ParticleRenderer::renderCache(maxCacheSize, nullptr);


ParticleRenderer::ParticleRenderer() 
: _blendFunc(BlendFunc::ALPHA_PREMULTIPLIED)
, _texture(nullptr)
, _particles(nullptr)
, _opacityModifyRGB(false)
, _quads(nullptr)
, _indices(nullptr)
, _VAOname(0)
, _totalParticles(0)
, _allocatedParticles(0)
, _particleCount(0)
, _particleIdx(0)
, _isAutoRemoveOnFinish(false)
, _emitterPos(Vec2(0,0))
, _emitter(nullptr)
, _emitterAngle(0)
{
	_positionType = positionType::RELATIVE;
	isFlowCircleRadius = false;
	flowCircleRadiusFireProId = 0;
	// Clear the memory
	memset(_buffersVBO , 0, sizeof(_buffersVBO));
}
ParticleRenderer::~ParticleRenderer() {
	CC_SAFE_FREE(_quads);
	CC_SAFE_FREE(_indices);
	glDeleteBuffers(2, &_buffersVBO[0]);
	if (Configuration::getInstance()->supportsShareableVAO())
	{
		glDeleteBuffers(1,&_VAOname);
		GL::bindVAO(0);
	}
	CC_SAFE_RELEASE(_texture);
	CC_SAFE_FREE(_particles);
}

ParticleRenderer* ParticleRenderer::create() {
	ParticleRenderer* render = new ParticleRenderer();
	if (render && render->init()) {
		render->autorelease();
		return render;
	}
	CC_SAFE_DELETE(render);
	return render;
}

void ParticleRenderer::onEnter() {
	Node::onEnter();
	
	/*this->scheduleUpdateWithPriority(ParticleRenderer::updatePriority);
	ParticleRenderer::updatePriority++;
	if (ParticleRenderer::updatePriority > 200) {
		ParticleRenderer::updatePriority = 0;
	}*/

	//this->scheduleUpdate();
}

void ParticleRenderer::onExit() {
	Node::onExit();

}

bool ParticleRenderer::init() {
	this->retain();

	return true;
}

bool ParticleRenderer::updateOneParticle(particleProperty& p, float dt , bool isUpdateRender /* = true */) {
	
	p.timeToLive -= dt;

	if (p.timeToLive > 0) {
		
		// 更新粒子 运动
		UpdateHelper::instance->updateParticleMove(p , dt);

		// 更新渲染队列 , 需要更新渲染时才更新渲染
		if (isUpdateRender) {
			// 再更新位置
			Vec2 newPos;
			if (_positionType == positionType::FREE)
			{
				newPos = p.pos;
				//newPos = Vec2(p.pos.x - _emitterPos.x, p.pos.y - _emitterPos.y);
				// 当particleEmitter 旋转时, 再逆向转回来
				/*if (_emitter && _emitter->getRotation() != 0 && _emitter->getIsActive()) {
					_emitterAngle = _emitter->getRotation();
				}*/

				// 加上这个粒子的 发射状态 时相对于 emitter 旋转角度的偏移量 ，
				//if (p.rotationPosOffset.x != 0 && p.rotationPosOffset.y != 0) {
				//	newPos = Vec2(newPos.x + p.rotationPosOffset.x, newPos.y + p.rotationPosOffset.y);
				//	float dis = newPos.getDistance(Vec2(0, 0));
				//	float angle = newPos.getAngle() / P_PI * 180;
				//	float angleOff = -angle - _emitterAngle; // 
				//	newPos = Vec2(dis*cosf(-angleOff / 180 * P_PI), dis*sinf(-angleOff / 180 * P_PI));
				//}
	
			}
			else if (_positionType == positionType::RELATIVE)
			{
				// 因为 render 加到 emitter 上,render的节点位置会跟着emitter的移动而移动，粒子的渲染又是在render节点的基础上
				newPos = p.pos;
			}

			if (isFlowCircleRadius) {
				Vec2 offset = Vec2(0, 0);
				if (_emitter && _emitter->isRunning() && _emitter->runningLayer) {
					auto firePro = _emitter->getFireProById(flowCircleRadiusFireProId);
					if (firePro) {
						offset = Vec2(firePro->_fireArea.inCircleRadius * cosf(p.startToCenterAngle / 180 * P_PI), firePro->_fireArea.inCircleRadius * sinf(p.startToCenterAngle / 180 * P_PI));
					}
				}
				newPos = Vec2(newPos.x + offset.x, newPos.y + offset.y);
			}

			this->updateQuadWithParticle(p, newPos ,dt);
		}

		++_particleIdx;
	}
	else {
		//粒子生命小于0
		if (_particleIdx != _particleCount - 1)
		{
			//直线最后一个,并再更新一次,因为长度缩小,即将便利不到最后一个
			_particles[_particleIdx] = _particles[_particleCount - 1];
			// 刷新一下指针，因为这里做了拷贝操作，导致一些预先指针错乱
			_particles[_particleIdx].refreshPointer();
		}
		--_particleCount;

		// 如果粒子数等于0了
		if (_particleCount == 0 && _isAutoRemoveOnFinish)
		{
			//this->unscheduleUpdate();
			//
			this->setScaleX(1);
			this->setScaleY(1);

			this->removeFromParent();
			if (ParticleRenderer::cacheSize >= ParticleRenderer::maxCacheSize) {
				this->release();
			}
			else {
				ParticleRenderer::renderCache.at(ParticleRenderer::cacheSize) = this;
				++ParticleRenderer::cacheSize;
			}

			return false;
		}
	}
	return true;
}

void ParticleRenderer::updateParticle(float dt , bool isUpdateRender/* = true*/) {
	_particleIdx = 0;

	// getWorldToNodeTransform()方法可以将世界坐标转换到一个Node的本地坐标来
	//Mat4 worldToNodeTM = getWorldToNodeTransform();
	
	if (_emitter && _emitter->runningLayer) {
		_emitterPos = _emitter->convertToWorldSpace(Vec2::ZERO);
		_emitterPos = _emitter->runningLayer->convertToNodeSpace(_emitterPos);

		// visible
		this->setVisible(_emitter->isVisible());
	}
	bool isHaveParLive = true;

	while (_particleIdx < _particleCount) {
		particleProperty* p = &_particles[_particleIdx];

		if (isUpdateRender) {
			//p->timeToLive -= dt;
		}
		else {
			dt = p->live - p->timeToLive;
		}

		isHaveParLive = this->updateOneParticle(*p, dt, isUpdateRender);

	}
	
	// only update gl buffer when visible
	if (_visible && isHaveParLive)
	{
		// 有关VAO & VBO 的操作可以不做，因为我们采用的是cocos的渲染命令渲染，而渲染命令里面做了VAO & VBO的操作我们这里不要多此一举，PS:如果自己渲染必须开启
		if (render_by_this_class) {
			postStep();
		}
	}

}

void ParticleRenderer::update(float dt) {
	float time1 = getNowTime();
	this->updateParticle(dt , true );
	float time2 = getNowTime();

	//CCLOG("draw render time:%f",time2 - time1);
}

particleProperty* ParticleRenderer::getNewParticlePtr() {
	if (_particleCount < _totalParticles)
	{
		return &_particles[_particleCount];
	}
	return nullptr;
}

bool ParticleRenderer::initWithTotalParticles(int totalParticleNum) {

	// 计数
	_totalParticles = totalParticleNum;

	// 分配内存
	CC_SAFE_FREE(_particles);
	_particles = (particleProperty*)calloc(_totalParticles, sizeof(particleProperty));

	if (!_particles) {
		CCLOG("Particle system: not enough memory");
		this->release();
		return false;
	}
	_allocatedParticles = totalParticleNum;

	// default blend function
	_blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;

	////////------------ 分配内存,渲染数据
	if (!this->allocMemory()) {
		this->release();
		return false;
	}

	this->initIndices();
	if (Configuration::getInstance()->supportsShareableVAO())
	{
		// 有关VAO & VBO 的操作可以不做，因为我们采用的是cocos的渲染命令渲染，而渲染命令里面做了VAO & VBO的操作我们这里不要多此一举，PS:如果自己渲染必须开启
		if (render_by_this_class) {
			setupVBOandVAO();
		}
	}
	else
	{
		// 有关VAO & VBO 的操作可以不做，因为我们采用的是cocos的渲染命令渲染，而渲染命令里面做了VAO & VBO的操作我们这里不要多此一举，PS:如果自己渲染必须开启
		if (render_by_this_class) {
			setupVBO();
		}
	}

	setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));

	return true;
}

bool ParticleRenderer::isFull() {
	return _particleCount == _totalParticles;
}

void ParticleRenderer::setupVBOandVAO() {
	// clean VAO
	glDeleteBuffers(2, &_buffersVBO[0]);
	glDeleteVertexArrays(1, &_VAOname);
	GL::bindVAO(0);

	glGenVertexArrays(1, &_VAOname);
	GL::bindVAO(_VAOname);

#define kQuadSize sizeof(_quads[0].bl)
	// 创建VBO顶点缓存对象
	glGenBuffers(2, &_buffersVBO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * _totalParticles, _quads, GL_DYNAMIC_DRAW);

	// vertices
	glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*)offsetof(V3F_C4B_T2F, vertices));

	// colors
	glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (GLvoid*)offsetof(V3F_C4B_T2F, colors));

	// tex coords
	glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_TEX_COORD);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*)offsetof(V3F_C4B_T2F, texCoords));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * _totalParticles * 6, _indices, GL_STATIC_DRAW);

	// Must unbind the VAO before changing the element buffer.
	GL::bindVAO(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	CHECK_GL_ERROR_DEBUG();
}
void ParticleRenderer::setupVBO() {
	// 删除 显卡上的缓冲区对象
	glDeleteBuffers(2, &_buffersVBO[0]);
	// 得到一个新的缓冲区对象
	glGenBuffers(2, &_buffersVBO[0]);

	// 绑定缓冲区 & 初始化缓冲区
	glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * _totalParticles, _quads, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * _totalParticles * 6, _indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	CHECK_GL_ERROR_DEBUG();
}

bool ParticleRenderer::allocMemory() {
	CC_SAFE_FREE(_quads);
	CC_SAFE_FREE(_indices);

	_quads = (V3F_C4B_T2F_Quad*)malloc(_totalParticles * sizeof(V3F_C4B_T2F_Quad));
	_indices = (GLushort*)malloc(_totalParticles * 6 * sizeof(GLushort));

	if (!_quads || !_indices)
	{
		CCLOG("cocos2d: Particle system: not enough memory");
		CC_SAFE_FREE(_quads);
		CC_SAFE_FREE(_indices);

		return false;
	}

	memset(_quads, 0, _totalParticles * sizeof(V3F_C4B_T2F_Quad));
	memset(_indices, 0, _totalParticles * 6 * sizeof(GLushort));

	return true;
}

void ParticleRenderer::initIndices() {
	for (int i = 0; i < _totalParticles; ++i)
	{
		const unsigned int i6 = i * 6;
		const unsigned int i4 = i * 4;
		_indices[i6 + 0] = (GLushort)i4 + 0;
		_indices[i6 + 1] = (GLushort)i4 + 1;
		_indices[i6 + 2] = (GLushort)i4 + 2;

		_indices[i6 + 5] = (GLushort)i4 + 1;
		_indices[i6 + 4] = (GLushort)i4 + 2;
		_indices[i6 + 3] = (GLushort)i4 + 3;
	}
}

void ParticleRenderer::postStep() {
	glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);

	// Option 1: Sub Data
	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_quads[0])*_totalParticles, _quads);
	
	// new 使用这一句 ,ios上会出现 opengl error 0x0501 , 这种情况出现在渲染交给cocos的情况下
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_quads[0])*_particleCount, _quads);

	// Option 2: Data
	// 使用这一句不会出现 opengl error 0x0501 , 这种情况出现在渲染交给cocos的情况下
	//glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * _particleCount, _quads, GL_DYNAMIC_DRAW);

	// Option 3: Orphaning + glMapBuffer
	 /*glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0])*_totalParticles, nullptr, GL_STREAM_DRAW);
	 void *buf = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	 memcpy(buf, _quads, sizeof(_quads[0])*_totalParticles);
	 glUnmapBuffer(GL_ARRAY_BUFFER);*/

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	CHECK_GL_ERROR_DEBUG();
}

void ParticleRenderer::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) {
	//CCASSERT(_particleIdx == 0 || _particleIdx == _particleCount, "Abnormal error in particle quad");
	if (render_by_this_class) {
		this->onDraw(transform, flags);
	}
	else {
		//quad command
		if (_particleIdx > 0)
		{
			_quadCommand.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, _quads, _particleIdx, transform, flags);
			renderer->addCommand(&_quadCommand);
		}
	}

	/*_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(ParticleRenderer::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);*/

	//this->onDraw(Mat4::ZERO, 100);
}

void ParticleRenderer::onDraw(const Mat4& transform, uint32_t flags) {
	///获取shaderstate
	auto glProgramState = getGLProgramState();

	glProgramState->apply(transform);

	//

	glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * _particleCount, _quads, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);

	GL::bindTexture2D(_texture->getName());

	GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);

#define quadSize sizeof(_quads[0].bl)
	// vertices
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, quadSize, (GLvoid*)offsetof(V3F_C4B_T2F, vertices));

	// colors
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, quadSize, (GLvoid*)offsetof(V3F_C4B_T2F, colors));

	// tex coords
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, quadSize, (GLvoid*)offsetof(V3F_C4B_T2F, texCoords));

	
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, _particleCount * 4);

	glDrawElements(GL_TRIANGLES, (GLsizei)_particleCount*6, GL_UNSIGNED_SHORT, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//GL::bindTexture2D(0);
	

}

void ParticleRenderer::setTexture(Texture2D* texture) {
	if (_texture != texture) {
		CC_SAFE_RETAIN(texture);
		CC_SAFE_RELEASE(_texture);
		_texture = texture;
		this->updateBlendFunc();
	}

	Size s = _texture->getContentSize();
	this->initTexCoordsWithRect(Rect(0, 0, s.width, s.height));
}

void ParticleRenderer::initTexCoordsWithRect(const Rect& pointRect) {
	// convert to Tex coords

	Rect rect = Rect(
		pointRect.origin.x * CC_CONTENT_SCALE_FACTOR(),
		pointRect.origin.y * CC_CONTENT_SCALE_FACTOR(),
		pointRect.size.width * CC_CONTENT_SCALE_FACTOR(),
		pointRect.size.height * CC_CONTENT_SCALE_FACTOR());

	GLfloat wide = (GLfloat)pointRect.size.width;
	GLfloat high = (GLfloat)pointRect.size.height;

	if (_texture)
	{
		wide = (GLfloat)_texture->getPixelsWide();
		high = (GLfloat)_texture->getPixelsHigh();
	}

#if CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL
	GLfloat left = (rect.origin.x * 2 + 1) / (wide * 2);
	GLfloat bottom = (rect.origin.y * 2 + 1) / (high * 2);
	GLfloat right = left + (rect.size.width * 2 - 2) / (wide * 2);
	GLfloat top = bottom + (rect.size.height * 2 - 2) / (high * 2);
#else
	GLfloat left = rect.origin.x / wide;
	GLfloat bottom = rect.origin.y / high;
	GLfloat right = left + rect.size.width / wide;
	GLfloat top = bottom + rect.size.height / high;
#endif // ! CC_FIX_ARTIFACTS_BY_STRECHING_TEXEL

	// Important. Texture in cocos2d are inverted, so the Y component should be inverted
	std::swap(top, bottom);

	V3F_C4B_T2F_Quad *quads = nullptr;
	unsigned int start = 0, end = 0;

	quads = _quads;
	start = 0;
	end = _totalParticles;


	for (unsigned int i = start; i<end; i++)
	{
		// bottom-left vertex:
		quads[i].bl.texCoords.u = left;
		quads[i].bl.texCoords.v = bottom;
		// bottom-right vertex:
		quads[i].br.texCoords.u = right;
		quads[i].br.texCoords.v = bottom;
		// top-left vertex:
		quads[i].tl.texCoords.u = left;
		quads[i].tl.texCoords.v = top;
		// top-right vertex:
		quads[i].tr.texCoords.u = right;
		quads[i].tr.texCoords.v = top;
	}

}

Texture2D* ParticleRenderer::getTexture() const {
	return _texture;
}

void ParticleRenderer::setBlendFunc(const BlendFunc &blendFunc) {
	if (_blendFunc.src != blendFunc.src || _blendFunc.dst != blendFunc.dst) {
		_blendFunc = blendFunc;
		this->updateBlendFunc();
	}
}
const BlendFunc& ParticleRenderer::getBlendFunc() const {
	return _blendFunc;
}

void ParticleRenderer::updateBlendFunc() {
	if (_texture)
	{
		// 获取是否预乘alpha 通道
		bool premultiplied = _texture->hasPremultipliedAlpha();

		_opacityModifyRGB = false;

		if (_texture && (_blendFunc.src == CC_BLEND_SRC && _blendFunc.dst == CC_BLEND_DST))
		{
			if (premultiplied)
			{
				_opacityModifyRGB = true;
			}
			else
			{
				_blendFunc = BlendFunc::ALPHA_NON_PREMULTIPLIED;
			}
		}
	}
}

void ParticleRenderer::updateQuadWithParticle(particleProperty& particle, const Vec2& newPosition , float dt) {
	V3F_C4B_T2F_Quad *quad;

	quad = &(_quads[_particleIdx]);

	// 当前经过的时间 在全部总生命中的百分比
	float nowTimePrecent = (particle.live - particle.timeToLive) / particle.live * 100;

	float alpha = particle.alpha.getParticleVarietyValue(nowTimePrecent);
	Color3B m_color = particle.color.getParticleVarietyValue(nowTimePrecent);  
	Color4B color = Color4B(m_color.r, m_color.g, m_color.b, alpha);
	color = (_opacityModifyRGB) ? Color4B(color.r * color.a / 255, color.g * color.a / 255, color.b * color.a / 255, color.a) :
		Color4B(color.r, color.g , color.b , color.a);


	quad->bl.colors = color;
	quad->br.colors = color;
	quad->tl.colors = color;
	quad->tr.colors = color;

	// vertices
	float size = particle.size.getParticleVarietyValue(nowTimePrecent);

	// 旋转
	float rotation = 0;
	if (particle.isLockRotationToMoveAngle) {
		rotation = -particle.moveAngle.getParticleVarietyValue(nowTimePrecent);
	}
	else {
		rotation = particle.rotation.getParticleVarietyValue(nowTimePrecent);
		if (particle.rotation.pType == particlePropertyType::constValue) {
			// 旋转速度
			float rotationSpeed = particle.rotationSpeed.getParticleVarietyValue(nowTimePrecent);
			particle.rotation.constValue += rotationSpeed * dt;
		}
	}


	// 倾斜角X Y
	float skewX = particle.skewX.getParticleVarietyValue(nowTimePrecent); 
	float skewY = particle.skewY.getParticleVarietyValue(nowTimePrecent);  

	if (particle.skewX.pType == particlePropertyType::constValue) {
		// 倾斜角X 速度
		float skewXSpeed = particle.skewXSpeed.getParticleVarietyValue(nowTimePrecent);  
		particle.skewX.constValue += skewXSpeed * dt;
	}

	// 倾斜角Y
	if (particle.skewY.pType == particlePropertyType::constValue) {
		// 倾斜角Y 速度
		float skewYSpeed = particle.skewYSpeed.getParticleVarietyValue(nowTimePrecent);  
		particle.skewY.constValue += skewYSpeed * dt;
	}

	if (rotation != 0)
	{
		GLfloat size_2 = size / 2;
		GLfloat x1 = -size_2;
		GLfloat y1 = -size_2;

		GLfloat x2 = size_2;
		GLfloat y2 = size_2;

		float myPosMat[8] = {
			x1 , y1 ,
			x2 , y1 ,
			x1 , y2 ,
			x2 , y2 ,
		};

		// 处理倾斜角X,Y  , 在旋转之前处理
		if (skewX > 0 || skewY > 0) {
			float skewMatArray[4] =
			{
				(float)sinf(CC_DEGREES_TO_RADIANS(skewY)), (float)sinf(CC_DEGREES_TO_RADIANS(skewX)),
				(float)cosf(CC_DEGREES_TO_RADIANS(skewX)), (float)cosf(CC_DEGREES_TO_RADIANS(skewY))
			};
			// bottom-left
			myPosMat[0] = 0 + myPosMat[0] * skewMatArray[2];
			myPosMat[1] = 0 + myPosMat[1] * skewMatArray[3];

			// bottom-right vertex:
			myPosMat[2] = 0 + myPosMat[2] * skewMatArray[2];
			myPosMat[3] = 0 + myPosMat[3] * skewMatArray[3];

			// top-left vertex:
			myPosMat[4] = 0 + myPosMat[4] * skewMatArray[2];
			myPosMat[5] = 0 + myPosMat[5] * skewMatArray[3];

			// top-right vertex:
			myPosMat[6] = 0 + myPosMat[6] * skewMatArray[2];
			myPosMat[7] = 0 + myPosMat[7] * skewMatArray[3];
		}


		GLfloat x = newPosition.x;
		GLfloat y = newPosition.y;

		GLfloat r = (GLfloat)-CC_DEGREES_TO_RADIANS(rotation);
		GLfloat cr = cosf(r);
		GLfloat sr = sinf(r);
		/*GLfloat ax = x1 * cr - y1 * sr + x;
		GLfloat ay = x1 * sr + y1 * cr + y;
		GLfloat bx = x2 * cr - y1 * sr + x;
		GLfloat by = x2 * sr + y1 * cr + y;
		GLfloat cx = x2 * cr - y2 * sr + x;
		GLfloat cy = x2 * sr + y2 * cr + y;
		GLfloat dx = x1 * cr - y2 * sr + x;
		GLfloat dy = x1 * sr + y2 * cr + y;*/

		GLfloat ax = myPosMat[0] * cr - myPosMat[1] * sr + x;
		GLfloat ay = myPosMat[0] * sr + myPosMat[1] * cr + y;
		GLfloat bx = myPosMat[2] * cr - myPosMat[3] * sr + x;
		GLfloat by = myPosMat[2] * sr + myPosMat[3] * cr + y;

		GLfloat cx = myPosMat[6] * cr - myPosMat[7] * sr + x;
		GLfloat cy = myPosMat[6] * sr + myPosMat[7] * cr + y;

		GLfloat dx = myPosMat[4] * cr - myPosMat[5] * sr + x;
		GLfloat dy = myPosMat[4] * sr + myPosMat[5] * cr + y;
		
		

		// 相对于锚点的偏移量
		Vec2 anchorPoint = Vec2(newPosition.x + (particle.anchorPoint.x - 0.5)*size , newPosition.y + (particle.anchorPoint.y - 0.5 )*size);
		float anchorDis = anchorPoint.getDistance(newPosition);
		float ahchorAngle = Vec2( anchorPoint.x - newPosition.x , anchorPoint.y - newPosition.y ).getAngle() / P_PI * 180;


		Vec2 rotatedAnchorPoint = Vec2(anchorDis * cosf((-ahchorAngle - rotation)/180*P_PI) , anchorDis * sinf((-ahchorAngle - rotation) / 180 * P_PI));


		// bottom-left
		quad->bl.vertices.x = ax + rotatedAnchorPoint.x;
		quad->bl.vertices.y = ay + rotatedAnchorPoint.y;

		// bottom-right vertex:
		quad->br.vertices.x = bx + rotatedAnchorPoint.x;
		quad->br.vertices.y = by + rotatedAnchorPoint.y;

		// top-left vertex:
		quad->tl.vertices.x = dx + rotatedAnchorPoint.x;
		quad->tl.vertices.y = dy + rotatedAnchorPoint.y;

		// top-right vertex:
		quad->tr.vertices.x = cx + rotatedAnchorPoint.x;
		quad->tr.vertices.y = cy + rotatedAnchorPoint.y;

	}
	else
	{
		// 根据 锚点 来设置渲染纹理的位置
		GLfloat leftWidth = particle.anchorPoint.x * size;
		GLfloat rightWidth = (1 - particle.anchorPoint.x) * size;
		GLfloat downHeight = particle.anchorPoint.y * size;
		GLfloat upHeight = (1 - particle.anchorPoint.y) * size;
		// 处理倾斜角X,Y  , 在旋转之前处理
		if (skewX > 0 || skewY > 0) {
			float skewMatArray[4] =
			{
				(float)sinf(CC_DEGREES_TO_RADIANS(skewY)), (float)sinf(CC_DEGREES_TO_RADIANS(skewX)),
				(float)cosf(CC_DEGREES_TO_RADIANS(skewX)), (float)cosf(CC_DEGREES_TO_RADIANS(skewY))
			};

			float myPosMat[8] = {
				-leftWidth , -downHeight ,
				rightWidth , -downHeight ,
				-leftWidth , upHeight ,
				rightWidth , upHeight ,
			};
			// bottom-left
			quad->bl.vertices.x = newPosition.x + myPosMat[0] * skewMatArray[2];
			quad->bl.vertices.y = newPosition.y + myPosMat[1] * skewMatArray[3];

			// bottom-right vertex:
			quad->br.vertices.x = newPosition.x + myPosMat[2] * skewMatArray[2];
			quad->br.vertices.y = newPosition.y + myPosMat[3] * skewMatArray[3];

			// top-left vertex:
			quad->tl.vertices.x = newPosition.x + myPosMat[4] * skewMatArray[2];
			quad->tl.vertices.y = newPosition.y + myPosMat[5] * skewMatArray[3];

			// top-right vertex:
			quad->tr.vertices.x = newPosition.x + myPosMat[6] * skewMatArray[2];
			quad->tr.vertices.y = newPosition.y + myPosMat[7] * skewMatArray[3];

		}
		else {
			// bottom-left vertex:
			quad->bl.vertices.x = newPosition.x - leftWidth;
			quad->bl.vertices.y = newPosition.y - downHeight;

			// bottom-right vertex:
			quad->br.vertices.x = newPosition.x + rightWidth;
			quad->br.vertices.y = newPosition.y - downHeight;

			// top-left vertex:
			quad->tl.vertices.x = newPosition.x - leftWidth;
			quad->tl.vertices.y = newPosition.y + upHeight;

			// top-right vertex:
			quad->tr.vertices.x = newPosition.x + rightWidth;
			quad->tr.vertices.y = newPosition.y + upHeight;
		}
	}

	

}

// 停在所有的粒子
void ParticleRenderer::stopAllParticles() {
	for (_particleIdx = 0; _particleIdx < _particleCount; ++_particleIdx) 
	{
		particleProperty* p = &_particles[_particleIdx];
		p->timeToLive = 0;
	}

}

void ParticleRenderer::setTotalParticles(int tp) {
	if (tp > _allocatedParticles)
	{
		_totalParticles = tp;

		// 分配内存
		CC_SAFE_FREE(_particles);
		_particles = (particleProperty*)calloc(_totalParticles, sizeof(particleProperty));

		if (!_particles) {
			CCLOG("Particle system: not enough memory");
			this->release();
		}
		_allocatedParticles = tp;

		// default blend function
		//_blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;

		////////------------ 分配内存,渲染数据
		if (!this->allocMemory()) {
			this->release();
		}

		this->initIndices();
		if (Configuration::getInstance()->supportsShareableVAO())
		{
			// 有关VAO & VBO 的操作可以不做，因为我们采用的是cocos的渲染命令渲染，而渲染命令里面做了VAO & VBO的操作我们这里不要多此一举，PS:如果自己渲染必须开启
			if (render_by_this_class) {
				setupVBOandVAO();
			}
		}
		else
		{
			// 有关VAO & VBO 的操作可以不做，因为我们采用的是cocos的渲染命令渲染，而渲染命令里面做了VAO & VBO的操作我们这里不要多此一举，PS:如果自己渲染必须开启
			if (render_by_this_class) {
				setupVBO();
			}
		}

		// fixed http://www.cocos2d-x.org/issues/3990
		// Updates texture coords.
		if (_texture) {
			Size s = _texture->getContentSize();
			this->initTexCoordsWithRect(Rect(0, 0, s.width, s.height));
		}

	}
	else
	{
		_totalParticles = tp;
	}

}
