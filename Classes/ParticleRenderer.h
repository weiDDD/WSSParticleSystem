/*
	wss 17/4/19

	绘制粒子系统中的所有粒子
*/

#pragma once
#ifndef _PARTICLE_RENDERER_H_
#define _PARTICLE_RENDERER_H_

#include "cocos2d.h"
using namespace cocos2d;

namespace pp {
	class ParticleEmitter;
};

namespace PRender {

#define P_PI 3.1415926

	struct mVec2{
		mVec2() {
			x = 0;
			y = 0;
		};
		mVec2(float rx,float ry) {
			x = rx;
			y = ry;
		};
		mVec2(const mVec2& copy) {
			x = copy.x;
			y = copy.y;
		}

		float x;
		float y;
	};



	// 粒子属性的类型
	enum particlePropertyType {
		none,
		// 一个值加值每帧的间隔 , 就是一个常值，没有间隔了(间隔废掉了，用曲线代替)
		constValue,
		// 曲线，横坐标为粒子生命周期
		curve
	};

	

	// 粒子属性值
	struct particleVarietyValue {
		particleVarietyValue() {
			pType = particlePropertyType::constValue;
			constValue = 0;
			delta = 0;
			curvePoints;
			isSetCurveKB = false;

			curveKbFirstPoint = nullptr;
		}
		~particleVarietyValue() {
		}

		void resetData();

		// 刷新一次地址的指针，因为当这个结构体被拷贝时会导致指针改变，curveKbFirstPoint指向不正确的地址
		void refreshPointer();

		float getParticleVarietyValue(float nowTime); 


		particlePropertyType pType;
		// 常值
		float constValue;
		// 常值每秒间隔
		float delta;
		// 曲线数据，横坐标为粒子生命周期 , 这个值应该 不是指针，这个值在 particleEmitter中的setParticleVarietyValue函数传入，
		std::vector<Vec2> curvePoints;

		// 首地址 & 大小
		Vec2* curvePointFirstPoint;
		int curvePointSize;

		float curveLeftPointX;
		float curveRightPointX;

		// 是否给KB赋值了,曲线点改变时，这个值为 false
		bool isSetCurveKB;
		// 曲线数据的 k,b值
		std::vector<Vec2> curveKB;

		// 首地址 & 大小
		Vec2* curveKbFirstPoint;

	};

	// 颜色曲线点
	struct colorCurvePoint {
		colorCurvePoint() {
			x = 0;
			colorY = Color3B(255, 255, 255);
			colorRand = Vec3(0, 0, 0);
			realColorY = Color3B(255, 255, 255);
		}

		float x;
		Color3B colorY;
		Vec3 colorRand;
		Color3B realColorY;   //+ colorRand 后的值
	};

	// 颜色属性值
	struct particleColorValue {
		particleColorValue() {
			pType = particlePropertyType::none;
			constColor = Color3B(0, 0, 0);
			deltaColor = Color3B(0, 0, 0);
			isSetRealColorY = false;
		}

		// 刷新一次地址的指针，因为当这个结构体被拷贝时会导致指针改变，curveKbFirstPoint指向不正确的地址
		void refreshPointer();

		void resetData();

		// 获取粒子 颜色 属性的函数
		Color3B getParticleVarietyValue(float nowTime);

		particlePropertyType pType;
		// 常值
		Color3B constColor;
		// 常值每秒间隔
		Color3B deltaColor;
		// 曲线数据，横坐标为粒子的生命周期
		std::vector<colorCurvePoint> curveColors;
		// 是否设置了 realColorY 
		bool isSetRealColorY;

		//// 一些 方便数据
		float curveLeftPointX;
		float curveRightPointX;
		colorCurvePoint* curveColorsFirstPtr;
		int curveColorsSize;

	};


	// 每个粒子的属性,最终的属性
	struct particleProperty {
		particleProperty() {
			gravitySpeedX = 0;
			gravitySpeedY = 0;
			isLockRotationToMoveAngle = false;
		}
		void resetData() {
			gravitySpeedX = 0;
			gravitySpeedY = 0;

			speed.resetData();
			acc.resetData();
			moveAngle.resetData();
			angleSpeed.resetData();
			gravityX.resetData();
			gravityY.resetData();
			size.resetData();
			rotation.resetData();
			rotationSpeed.resetData();
			skewX.resetData();
			skewXSpeed.resetData();
			skewY.resetData();
			skewYSpeed.resetData();
			alpha.resetData();
			color.resetData();
		}

		void refreshPointer() {
			speed.refreshPointer();
			acc.refreshPointer();
			moveAngle.refreshPointer();
			angleSpeed.refreshPointer();
			gravityX.refreshPointer();
			gravityY.refreshPointer();
			size.refreshPointer();
			rotation.refreshPointer();
			rotationSpeed.refreshPointer();
			skewX.refreshPointer();
			skewXSpeed.refreshPointer();
			skewY.refreshPointer();
			skewYSpeed.refreshPointer();
			alpha.refreshPointer();
			color.refreshPointer();
		}

		// 是否锁定旋转角度为移动角度，锁定后，旋转角度和移动角度一致
		bool isLockRotationToMoveAngle;

		//发射时的 相对于中心点的角度
		float startToCenterAngle = 0;
		// 发射时，发射器的位置
		Vec2 emitterPos;
		// 发射时，粒子跟随发射器旋转后的偏移量
		Vec2 rotationPosOffset;

		// 生命
		float live;
		// 生命
		float timeToLive;
		//位置
		Vec2 pos;
		// 锚点
		Vec2 anchorPoint;
		float anchorPointDis;// 锚点距离(0.5,0.5)的距离
		float anchorPointAngle;// 锚点距离(0.5,0.5)的角度
		// 粒子的发射器,开始的位置
		Vec2 startPos;
		//速度
		particleVarietyValue speed;
		float speedX;
		float speedY;

		float gravitySpeedX;
		float gravitySpeedY;

		// 发射开始时，发射器的pos
		Vec2 emitterStartPos;
		Vec2 nowEmitterPos;

		// 加速度
		particleVarietyValue acc;
		//运动角度
		particleVarietyValue moveAngle;
		// 角速度
		particleVarietyValue angleSpeed;
		// 重力X
		particleVarietyValue gravityX;
		// 重力Y
		particleVarietyValue gravityY;
		// 大小
		particleVarietyValue size;
		// 旋转角度
		particleVarietyValue rotation;
		// 旋转角度速度
		particleVarietyValue rotationSpeed;
		// 倾斜角X
		particleVarietyValue skewX;
		// 倾斜角X 速度
		particleVarietyValue skewXSpeed;
		// 倾斜角Y 
		particleVarietyValue skewY;
		// 倾斜角Y 速度
		particleVarietyValue skewYSpeed;

		// 不透明度
		particleVarietyValue alpha;

		// 颜色
		particleColorValue color;

	};


	// 粒子的位置类型,
	enum positionType {
		positionTypeNone,
		FREE,
		RELATIVE,
	};

	// 渲染模式
	enum renderMode {
		TRIANGLES,
		TRIANGLE_STRIP,
		LINES
	};

	class ParticleRenderer :public Node, public TextureProtocol
	{
	public:
		static int updatePriority;

		// 搞一个静态的存储器
		static int cacheSize;
		static int maxCacheSize;
		static std::vector<ParticleRenderer*> renderCache;
		
		// int 类型数组，包括开始指针，和数组大小
		struct intVec {
			intVec(const int* f, int s) {
				vec = (const int*)f;
				size = (GLsizei)s;
			}
			const int* vec;
			GLsizei size;
		};
		// float 类型数组，包括开始指针，和数组大小
		struct floatVec {
			floatVec(const float* f, int s) {
				vec = (const float*)f;
				size = (GLsizei)s;
			}
			const float* vec;
			GLsizei size;
		};

		ParticleRenderer();
		~ParticleRenderer();

		static ParticleRenderer* create();
		virtual void onEnter();
		virtual void onExit();
		virtual void update(float dt);
		virtual bool init();

		// 真正的更新，参数：是否更新渲染
		void updateParticle(float dt , bool isUpdateRender = true);

		bool updateOneParticle(particleProperty& p,float dt , bool isUpdateRender = true);

		// 初始化, 参数:最大的粒子数量
		bool initWithTotalParticles(int totalParticleNum);

		// 设置最大粒子数
		void setTotalParticles(int tp);

		// draw 函数重写
		virtual void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags) override;
		virtual void setTexture(Texture2D* texture) override;
		virtual Texture2D* getTexture() const override;
		virtual void setBlendFunc(const BlendFunc &blendFunc) override;
		virtual const BlendFunc &getBlendFunc() const override;

		void initTexCoordsWithRect(const Rect& rect);

		// 分配 渲染队列的内存
		bool allocMemory();
		// 初始化 顶点索引
		void initIndices();

		// 设置开启VBO,VAO
		void setupVBOandVAO();
		void setupVBO();

		virtual void postStep();

		virtual void updateBlendFunc();
		// 更新渲染一个粒子的渲染
		void updateQuadWithParticle(particleProperty& particle, const Vec2& newPosition,float dt);

		// 当前粒子数量是否达到了粒子最大数量
		bool isFull();

		// 获取最大粒子数量
		int getTotalParticles() { return _totalParticles; }
		int getAllocatedParticles() { return _allocatedParticles; }
		int getParticleCount() { return _particleCount; }
		void setParticleCount(int count) { _particleCount = count; }
		void addParticleCount() { ++_particleCount; }
		void setIsAutoRemoveOnFinish(bool autoRemove) { _isAutoRemoveOnFinish = autoRemove; }
		void setPositionType(positionType t) { _positionType = t; }
		positionType getPositionType() { return _positionType ; }
		void setEmitterPos(Vec2 pos) { _emitterPos = pos; }

		void onDraw(const Mat4& transform, uint32_t flags);

		// 设置渲染模式
		void setRenderMode(renderMode mode){ _renderMode = mode; }

		// 停在所有的粒子
		void stopAllParticles();

		// 获得一个新的粒子的指针
		particleProperty* getNewParticlePtr();

		pp::ParticleEmitter* _emitter;

		bool isFlowCircleRadius;
		int flowCircleRadiusFireProId;
		
		///////////////////////////////////////////////// 设置shader文件
		std::string vshName = "";
		std::string fshName = "";
		void setShaderFile(std::string vName, std::string fName){
			vshName = vName;
			fshName = fName;

			auto pProgram = GLProgram::createWithFilenames(vshName, fshName);
			///创建shaderstate  shader状态
			auto glprogramstate = GLProgramState::getOrCreateWithGLProgram(pProgram);
			///设置shader
			setGLProgramState(glprogramstate);
		}

		////设置第二重纹理
		void setSecondTex(std::string name){
			auto image = new (std::nothrow) Image();
			std::string fullpath = FileUtils::getInstance()->fullPathForFilename(name);
			bool bRet = image->initWithImageFile(fullpath);

			texture = new (std::nothrow) Texture2D();

			if (texture && texture->initWithImage(image)) {
				image->release();
				tex = texture->getName();
			}
			//tex = Director::getInstance()->getTextureCache()->addImage(name)->getName();
		}

		/////所有参数的map
		std::map<std::string, float> floatArgMap;    ///float类型的参数的map
		std::map<std::string, int> intArgMap;
		std::map<std::string, Vec2> vec2ArgMap;
		std::map<std::string, Vec3> vec3ArgMap;
		std::map<std::string, Vec4> vec4ArgMap;

		///向外部提供设置上面参数的接口
		void setFloatArg(std::string argKeyName, float value);
		void setIntArg(std::string argKeyName, int value);
		void setVec2Arg(std::string argKeyName, Vec2 value);
		void setVec3Arg(std::string argKeyName, Vec3 value);
		void setVec4Arg(std::string argKeyName, Vec4 value);

		// 传递数组数据 , 暂时只支持int 和 float类型
		// 给C++ 工程的接口
		void setIntVecArg(std::string argKeyName, const int* ptr, ssize_t size);
		// 给lua 的接口
		void setIntVecArgLua(std::string argKeyName, const cocos2d::ValueVector &ptr, ssize_t size);
		std::map<std::string, intVec> intVecArgMap;


		// 给C++ 工程的接口
		void setFloatVecArg(std::string argKeyName, float* ptr, ssize_t size);
		// 给lua 的接口
		void setFloatVecArgLua(std::string argKeyName, const cocos2d::ValueVector &ptr, ssize_t size);
		std::map<std::string, floatVec> floatVecArgMap;

		////清掉所有的参数
		void clearAllArgMap();

		void clearData();

		void setCacheTransform() {
			_isSetCacheTransform = true;
		}

		///第二层纹理
		Texture2D* texture;
		GLuint tex;

	private:
		//////------ 绘制相关
		/** conforms to CocosNodeTexture protocol */
		BlendFunc _blendFunc;
		// 纹理
		Texture2D* _texture;

		// 是否alpha * rgb
		bool _opacityModifyRGB;
		// VAO & VBO 相关
		V3F_C4B_T2F_Quad    *_quads;        // quads to be rendered
		GLushort            *_indices;      // indices 顶点索引
		GLuint              _VAOname;
		GLuint              _buffersVBO[2]; //0: vertex  1: indices

		QuadCommand _quadCommand;           // quad command

		CustomCommand _customCommand;
		/////////---------------
		// 渲染模式
		renderMode _renderMode;

		// 放完是否自动死亡
		bool _isAutoRemoveOnFinish;
		//
		// 所有要显示的粒子的数据
		particleProperty* _particles;
		// 当前允许的最大粒子数量，这个值一定是 <= _allocatedParticles
		int _totalParticles;
		// 已经分配了内存的粒子数量，
		int _allocatedParticles;
		// 当前的粒子数量，系统中活着的粒子数量
		int _particleCount;

		//!  粒子索引
		int _particleIdx;
		// 粒子的位置运动类型,自由 or 相对
		positionType _positionType;

		// 发射器的位置
		Vec2 _emitterPos;

		// 发射器的旋转角度
		float _emitterAngle;

		// 发射器的缩放
		float _emitterScaleX;
		float _emitterScaleY;

		cocos2d::Mat4 cacheTransform;
		bool _isSetCacheTransform;
	};

}

#endif