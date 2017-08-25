/*
wss 17/4/19

粒子系统中的发射器
*/

#pragma once

#ifndef _PARTICLE_EMITTER_H_
#define _PARTICLE_EMITTER_H_

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

#include "cocos2d.h"
#include "ParticleRenderer.h"
using namespace cocos2d;
using namespace PRender;

#define infiniteLife 999999999

namespace pp {
	class ParticleEmitter;
}


/////混合模式
static int getBlendTypeByInt(int i) {
	if (i == 0) {
		return GL_ZERO;
	}
	else if (i == 1) {
		return GL_ONE;
	}
	else if (i == 2) {
		return GL_SRC_COLOR;
	}
	else if (i == 3) {
		return GL_ONE_MINUS_SRC_COLOR;
	}
	else if (i == 4) {
		return GL_DST_COLOR;
	}
	else if (i == 5) {
		return GL_ONE_MINUS_DST_COLOR;
	}
	else if (i == 6) {
		return GL_SRC_ALPHA;
	}
	else if (i == 7) {
		return GL_ONE_MINUS_SRC_ALPHA;
	}
	else if (i == 8) {
		return GL_DST_ALPHA;
	}
	else if (i == 9) {
		return GL_ONE_MINUS_DST_ALPHA;
	}
	else if (i == 10) {
		return GL_SRC_ALPHA_SATURATE;
	}
}
static int getIntByBlendType(int i) {
	if (i == GL_ZERO) {
		return 0;
	}
	else if (i == GL_ONE) {
		return 1;
	}
	else if (i == GL_SRC_COLOR) {
		return 2;
	}
	else if (i == GL_ONE_MINUS_SRC_COLOR) {
		return 3;
	}
	else if (i == GL_DST_COLOR) {
		return 4;
	}
	else if (i == GL_ONE_MINUS_DST_COLOR) {
		return 5;
	}
	else if (i == GL_SRC_ALPHA) {
		return 6;
	}
	else if (i == GL_ONE_MINUS_SRC_ALPHA) {
		return 7;
	}
	else if (i == GL_DST_ALPHA) {
		return 8;
	}
	else if (i == GL_ONE_MINUS_DST_ALPHA) {
		return 9;
	}
	else if (i == GL_SRC_ALPHA_SATURATE) {
		return 10;
	}
}

// 发射器 的 属性值的类型
enum emitterPropertyType {
	// 功能未打开
	none,
	//一个常量
	oneConstant,
	//多个常量中的一个
	moreConstant,
	//两个常量之间的随机值
	randBetweenTwoConst,
	//开始结束值 + 开始结束波动值
	//startEndRand,
	//曲线
	curve,
};

// 支持多种赋值方式的属性值,多样值
struct emitterVarietyValue {
	emitterVarietyValue() {
		pType = emitterPropertyType::oneConstant;
		constValue = 0;
		randConst1 = 0;
		randConst2 = 0;

		isSetCurveKB = false;

		//curvePoints.push_back(Vec3(0, 0, 0));
		//curvePoints.push_back(Vec3(1, 10, 0));
	}
	// 注意这里，在函数传参，赋值对象时 可能调用复制构造函数，但是当复制出的对象在其生命周期死亡后会调用 析构函数， 这里可能出错(所以一般函数传参就是传引用参数)
	~emitterVarietyValue() {
	}

	//写数据到json文件中
	void writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator, char* nameKey);
	// 从json文件中读数据
	void readJsonData(rapidjson::Document& doc, char* nameKey);

	// 值得类型
	emitterPropertyType pType;
	// 一个常值
	float constValue;
	// 多个常值之一
	std::vector<float> constValues;
	// 两个常值 之间的随机值
	float randConst1;
	float randConst2;

	// 曲线数据 ， x 横坐标 (发射周期  或  粒子生命 )，y 纵坐标 (具体值) ，z : y坐标的随机值 
	std::vector<Vec3> curvePoints;
	// 是否给KB赋值了,曲线点改变时，这个值为 false
	bool isSetCurveKB;
	// 曲线数据的 k,b值
	std::vector<Vec2> curveKB;
	// 发射时的粒子属性的曲线数据的  上下随机曲线的K，B值 , 因为发射时的粒子属性如果是曲线数据，那么render得到的数据是这个曲线中的一个值，所以需要保存一下这个上下随机曲线的KB值，保证性能
	std::vector<Vec2> randUpCurveKB;
	std::vector<Vec2> randDownCurveKB;

};

// 发射区域类型
enum fireAreaType {
	rect,
	circle,
	polygon,  // 自定义多边形
	lines,    // 自定义线条
};

// 三角形结构体
struct triangle {
	Vec2 point1;
	Vec2 point2;
	Vec2 point3;
	float areaSize;   //面积
};
// 发射区域的多种值
struct varietyFireAreaValue {
	varietyFireAreaValue() {
		fAreaType = fireAreaType::rect;
		inRect = Size(0, 0);
		outRect = Size(50, 50);
		inCircleRadius = 0;
		outCircleRadius = 50;
		isEdgeFire = false;
		edgeFireWidth = 0;

		polygonPoints.push_back(Vec2(-100, 0));
		polygonPoints.push_back(Vec2(0, 120));
		polygonPoints.push_back(Vec2(100, 0));
		
		linePoints.push_back(Vec2(-50,0));
		linePoints.push_back(Vec2(50, 0));

		isChangePolygonToTriangleVec = false;
	}
	bool operator != (const varietyFireAreaValue &var) {
		if (fAreaType != var.fAreaType)
			return true;
		if (inRect.width != var.inRect.width || inRect.height != var.inRect.height || outRect.width != var.outRect.width || outRect.height != var.outRect.height || 
			inCircleRadius != var.inCircleRadius || outCircleRadius != var.outCircleRadius || isEdgeFire != var.isEdgeFire || edgeFireWidth != var.edgeFireWidth)
			return true;
		if (polygonPoints.size() != var.polygonPoints.size())
			return true;
		if (linePoints.size() != var.linePoints.size())
			return true;
		for (int i = 0; i < polygonPoints.size(); ++i) {
			if (polygonPoints.at(i) != var.polygonPoints.at(i)) {
				return true;
			}
		}
		for (int i = 0; i < linePoints.size(); ++i) {
			if (linePoints.at(i) != var.linePoints.at(i)) {
				return true;
			}
		}

		return false;
	}
	// 设置线段的距离
	void setPolygonAndLineAreaLineDis();
	// 将自身数据写到json文件中
	void writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator, char* nameKey);
	// 从json文件中读数据
	void readJsonData(rapidjson::Document& doc, char* nameKey);


	fireAreaType fAreaType;
	Size inRect;
	Size outRect;
	float inCircleRadius;
	float outCircleRadius;
	std::vector<Vec2> polygonPoints;
	// 多边形顶点的 距离 的数组
	std::vector<float> polygonLinesDis;

	// 将多边形划分成多个三角形 的集合
	std::vector<triangle> polygonTriangleVec;
	// 是否将 多边形拆分成多个三角形了？
	bool isChangePolygonToTriangleVec;

	std::vector<Vec2> linePoints;
	// 多边形顶点的 距离 的数组
	std::vector<float> lineLinesDis;
	// 是否沿着自定义多边形边缘 或 自定义线条 发射
	bool isEdgeFire;
	float edgeFireWidth;
};

// 发射角度类型
enum fireAngleType {
	global, // 全局的
	local,  // 本地的，圆形发射器:从中心到发射点的角度，矩形:从中心到边的角度，自定义:中心到发射点
};

// 颜色数据
struct emitterColorValue {
	emitterColorValue() {
		pType = emitterPropertyType::none;
		constColor = Color3B(255, 255, 255);
		randColor1 = Color3B(255, 255, 255);
		randColor2 = Color3B(255, 255, 255);
	}

	// 写数据到json文件中
	void writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator, char* nameKey);
	// 从json文件中读数据
	void readJsonData(rapidjson::Document& doc, char* nameKey);

	// 值得类型
	emitterPropertyType pType;
	// 一种颜色
	Color3B constColor;
	// 两种颜色之间随机
	Color3B randColor1;
	Color3B randColor2;
	// 多种颜色之一
	std::vector<Color3B> constColors;
	// 颜色条,横坐标为发射周期 或 粒子生命周期,Y为对应时刻的颜色值
	std::vector<colorCurvePoint> curveColors;
};


// 拖尾属性
struct tailPro {
	tailPro() {
		tailNode = nullptr;
		isActive = false;
		fade = 0.2;
		minSeg = 6;
		stroke = 16;
		color = Color3B(255, 255, 255);
	}
	~tailPro() {
		if (tailNode) {
			if (tailNode->getParent()) {
				tailNode->removeFromParent();
			}
			tailNode = nullptr;
		}
	}
	// 刷新拖尾
	void refreshTailData();

	MotionStreak* tailNode;

	// 写数据到json文件中
	void writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator, char* nameKey);
	// 从json文件中读数据
	void readJsonData(rapidjson::Document& doc, char* nameKey);

	// 是否启用
	bool isActive;
	// 纹理
	std::string tailName;
	// 消逝时间
	float fade;
	// 最小长度
	float minSeg;
	// 宽度
	float stroke;
	Color3B color;
};

enum parType {
	render,
	emitter,
};

//// 发射数据
struct emitterFirePro {
	emitterFirePro() {
		nowTexName = "";
		nowMaxParticleNum = 0;
		nowPositionType = positionType::positionTypeNone;

		_localZorder = 0;
		_tagName = "";
		_emitterFileName = "";
		_isActive = true;
		_emitCounter = 0;
		_elapsed = 0;
		_isDoPreFire = false;
		_isDoDelayTime = false;

		_debugDrawNode_centerPoint = nullptr;

		_debugDrawNode_fireAreaMode = nullptr;

		nowTexName = "";
		nowMaxParticleNum = 0;

		_texName = "";
		_texAnchorPoint = Vec2(0.5, 0.5);
		_maxParticleNum = 100;
		_angleType = fireAngleType::global;
		_emissionRate = 0;
		_duration = 0;
		_positionType = positionType::FREE;
		_sourceBlend = GL_SRC_ALPHA;
		_destBlend = GL_ONE;
		_isLoop = false;
		_preFireDuration = 0;
		_delayTime = 0;
	}
	~emitterFirePro() {
		if (_debugDrawNode_centerPoint) {
			if (_debugDrawNode_centerPoint->getParent()) {
				_debugDrawNode_centerPoint->removeFromParent();
			}
		}
		if (_debugDrawNode_fireAreaMode) {
			if (_debugDrawNode_fireAreaMode->getParent()) {
				_debugDrawNode_fireAreaMode->removeFromParent();
			}
		}
	}

	void stopFirePro() {

	}

	void resetData() {
		nowTexName = "";
		nowMaxParticleNum = 0;
		nowPositionType = positionType::positionTypeNone;
		_isActive = true;
		_emitCounter = 0;
		_elapsed = 0;
		_isDoPreFire = false;
		_isDoDelayTime = false;
		if (_tailPro.tailNode) {
			if (_tailPro.tailNode->getParent()) {
				_tailPro.tailNode->removeFromParent();
				_tailPro.tailNode = nullptr;
			}
		}
	}

	// 写数据到json文件
	bool writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator);
	// 从json文件中读数据
	void readJsonData(rapidjson::Document& doc);

	// ----- debug  drawNode
	DrawNode* _debugDrawNode_centerPoint;

	DrawNode* _debugDrawNode_fireAreaMode;

	//// ---------------------其他用来和 发射器数据 进行对比设置 的临时值
	// 当前的纹理名称
	std::string nowTexName;
	// 当前的粒子最大数量
	int nowMaxParticleNum;
	// 当前的发射区域的数据 , 用来与 firePro中的数据进行比较的
	varietyFireAreaValue nowFireAreaData;
	// 当前的位置运动模式
	positionType nowPositionType;

	//// ----- 发射运算 的一些属性
	// 粒子 发射器 系统是否激活
	bool _isActive;
	////////////////
	// 发射计时器
	float _emitCounter;
	// 消逝的时间
	float _elapsed;
	// 是否执行了预发射
	bool _isDoPreFire;
	// 是否执行了延迟发射
	bool _isDoDelayTime;

	// -------------------------------- 发射器属性：  (一下属性需要记录)
	// 这个发射属性的别名，用户写的用来方便标识的
	std::string _tagName;
	// local zorder
	int _localZorder;
	// id
	int _id;
	// 类型，是render or emitter
	parType _parType;
	// emitter 粒子的文件名
	std::string _emitterFileName;
	//纹理
	std::string _texName;

	// 纹理锚点
	Vec2 _texAnchorPoint;

	// 最大粒子数量
	int _maxParticleNum;

	// 粒子的位置运动类型,自由 or 相对
	positionType _positionType;

	//////混合模式
	int _sourceBlend;
	int _destBlend;

	// 运动的角度类型
	fireAngleType _angleType;

	//发射速率
	float _emissionRate;
	
	// 粒子发射的周期
	float _duration;
	// 是否循环发射
	bool _isLoop;

	// 预发射几个周期的粒子
	float _preFireDuration;
	
	// 发射开始的延迟, 单位：秒
	float _delayTime;

	// 发射区域
	varietyFireAreaValue _fireArea;

	// 拖尾属性
	tailPro _tailPro;

	// ----------------------------- 发射时的粒子属性：
	// 粒子的生命
	emitterVarietyValue _life;
	// 发射时的粒子速度
	emitterVarietyValue _startMoveSpeed;
	// 发射时的粒子 加速度
	emitterVarietyValue _startMoveAcc;
	// 发射时的粒子移动角度
	emitterVarietyValue _startMoveAngle;
	// 发射时的粒子的 角速度
	emitterVarietyValue _startMoveAngleSpeed;
	// 发射时的粒子的 重力X
	emitterVarietyValue _startGravityX;
	// 发射时的粒子的 重力Y
	emitterVarietyValue _startGravityY;
	// 发射时的粒子的大小
	emitterVarietyValue _startSize;
	// 发射时的粒子的旋转角度
	emitterVarietyValue _startRotation;
	// 发射时的粒子的旋转速度
	emitterVarietyValue _startRotationSpeed;
	// 发射时的粒子的倾斜角X
	emitterVarietyValue _startSkewX;
	// 发射时的粒子的倾斜角X 速度
	emitterVarietyValue _startSkewXSpeed;
	// 发射时的粒子的倾斜角Y
	emitterVarietyValue _startSkewY;
	// 发射时的粒子的倾斜角Y 速度
	emitterVarietyValue _startSkewYSpeed;
	// 发射时的粒子的不透明度
	emitterVarietyValue _startAlpha;

	// 发射时的粒子的颜色
	emitterColorValue _startColor;

	////------------- 额外属性. 粒子在其生命周期内的一些属性，默认为关闭状态，若打开则会取代 开始的属性。
	// 粒子生命周期内的移动 速度
	emitterVarietyValue _moveSpeedOfLife;
	// 粒子生命周期内的移动 加速度
	emitterVarietyValue _moveAccOfLife;
	// 粒子生命周期内的移动 角度
	emitterVarietyValue _moveAngleOfLife;
	// 粒子生命周期内的 角速度
	emitterVarietyValue _moveAngleSpeedOfLife;
	// 粒子生命周期内的 重力X
	emitterVarietyValue _gravityXOfLife;
	// 粒子生命周期内的 重力Y
	emitterVarietyValue _gravityYOfLife;
	// 粒子生命周期内的 大小
	emitterVarietyValue _sizeOfLife;
	// 粒子生命周期内的 旋转角度
	emitterVarietyValue _rotationOfLife;
	// 粒子生命周期内的 旋转速度
	emitterVarietyValue _rotationSpeedOfLife;
	// 粒子生命周期内的 倾斜角X
	emitterVarietyValue _skewXOfLife;
	// 粒子生命周期内的 倾斜角X速度
	emitterVarietyValue _skewXSpeedOfLife;
	// 粒子生命周期内的 倾斜角Y
	emitterVarietyValue _skewYOfLife;
	// 粒子生命周期内的 倾斜角Y速度
	emitterVarietyValue _skewYSpeedOfLife;
	// 粒子生命周期内的 不透明度
	emitterVarietyValue _alphaOfLife;

	// 粒子生命周期内的颜色值
	emitterColorValue _colorOfLife;

};

// 子发射器结构体
struct emitterPar {
	emitterPar() {
		par = nullptr;
	}
	pp::ParticleEmitter* par;
	particleProperty pro;
};

// 发射出来的 子粒子 ：可能是渲染器 或者 发射器数组
struct childrenPar {
	childrenPar() {
		_renderer = nullptr;
		_totalParticles = 0;
		_particleCount = 0;

	}
	void setTexture(Texture2D* texture) {
		if (_renderer) {
			_renderer->setTexture(texture);
		}
	}
	void setTotalParticles(int tp, Node* father, std::string emitterFileName);

	void setPositionType(positionType t) {
		_positionType = t;
		if (_renderer) {
			_renderer->setPositionType(t);
		}
	}
	void setBlendFunc(const BlendFunc &blendFunc) {
		if (_renderer) {
			_renderer->setBlendFunc(blendFunc);
		}
	}
	int getParticleCount() {
		if (_renderer) {
			return _renderer->getParticleCount();
		}
		else {
			return _particleCount;  //_emitter.size();
		}
	}
	int getTotalParticles() {
		if (_renderer) {
			return _renderer->getTotalParticles();
		}
		else {
			return _totalParticles;
		}
	}
	particleProperty* addParticle(Node* father, std::string emitterFileName, int localZorder);

	void updateOneParticle(particleProperty& p, float dt, bool isUpdateRender = true);

	void resetData();

	void clearData();

	ParticleRenderer* _renderer;
	////////////////////////////////////////////emitter par
	// 最大的粒子数量
	int _totalParticles;
	// 当前的粒子数量，系统中活着的粒子数量
	int _particleCount;
	// 粒子的位置运动类型,自由 or 相对
	positionType _positionType;
	std::vector<emitterPar*> _emitter;
};


namespace pp {
class ParticleEmitter : public Node
	{
	public:

	public:
		static int updatePriority;

		ParticleEmitter();
		~ParticleEmitter();

		static ParticleEmitter* instance;
		static ParticleEmitter* create();
		static ParticleEmitter* create(bool isInstance);

		ParticleEmitter* createEmitter();

		// 为发射器设置一组测试的粒子效果数据
		void setTestData(emitterFirePro& pro);

		virtual void onEnter() override;
		virtual void onExit() override;
		virtual void update(float dt);
		virtual bool init();

		virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);

		void stopSystem();
		void resetSystem();

		void setIsAutoRemoveOnFinish(bool autoRemove) { _isAutoRemoveOnFinish = autoRemove; }

		// 写数据到json文件
		bool writeJsonData(rapidjson::Document& object, rapidjson::Document::AllocatorType& allocator);
		// 从json文件中读数据
		void readJsonData(rapidjson::Document& doc);

		// 
		void readJsonDataFromFile(std::string filename);

		// getset
		bool getIsActive() { return _isActive; }

		emitterFirePro* getFireProById(int id) {
			auto itor = fireProVec.begin();
			while (itor != fireProVec.end()) {
				if ((*itor)->_id == id) {
					return (*itor);
				}
				itor++;
			}
			return nullptr;
		}
		emitterFirePro* getFirstFirePro() {
			auto itor = fireProVec.begin();
			while (itor != fireProVec.end()) {
				return (*itor);
				itor++;
			}
			return nullptr;
		}
		void removeFireProById(int id);

		// 粒子发射器死亡后会把render放到的节点
		Node* runningLayer;
		void setRunningLayer(Node* layer);

		// 是否绘制drawNode
		static bool isUseDrawNode;

		childrenPar* getChildrenParById(int id);

		void setChildrenParNewId(int oldid, int newid);

		// 创建发射属性的唯一id
		static int fireProId;
		// 加一个发射属性,
		emitterFirePro* addOneFirePro(int id, parType type, std::string fileName );

		// 清理一波数据
		void clearData();

		void addRender(bool isCreateNew = false);
		void releaseRender();   // 自由就不管，相对就加到runlayer上自己死亡
		void clearRender();     // 强行删掉

		void refreshZorder();

		// 世界位置
		Vec2 worldPos;

		/////--------------发射器数据
		std::vector<emitterFirePro*> fireProVec;

		static void setSourcePath(std::string path);
		static std::string sourcePath;
	private:

		// 是否在发射完后自动死亡
		bool _isAutoRemoveOnFinish;

		// 粒子 发射器 系统是否激活
		bool _isActive;

		/////////////////------ 作为子粒子发射器的属性相关
		std::map<int, childrenPar*> childrenParMap;

	public:
		///// ----------------------------------------------------- 提供给外部的修改 firePro 的函数-----------------------------------------------------------------------
		void setFirePro_ParType(int id, std::string type);
		void setFirePro_EmitterFileName(int id, std::string name);
		void setFirePro_TexName(int id, std::string texName);
		void setFirePro_AnchorPoint(int id, float x, float y);
		void setFirePro_MaxParticleNum(int id, int num);
		void setFirePro_PositionType(int id, std::string type);
		void setFirePro_SourceBlend(int id, int sourceBlend);
		void setFirePro_DestBlend(int id, int destBlend);
		void setFirePro_FireAngleType(int id, std::string type);
		void setFirePro_emissionRate(int id, float rate);
		void setFirePro_duration(int id, float duration);
		void setFirePro_isLoop(int id, bool loop);
		void setFirePro_preFireDuration(int id, float preFire);
		void setFirePro_delayTime(int id, float delay);
		// -- 发射区域
		void setFirePro_fireArea(int id, float inRectWidth, float inRectHeight, float outRectWidth, float outRectHeight); // rect
		void setFirePro_fireArea(int id, float inCirecleRadius, float outCircleRadius); // circle
		void setFirePro_fireArea_clear(int id);
		void setFirePro_fireArea_pushPolygonPoint(int id, float posX, float posY);
		void setFirePro_fireArea_pushLinePoint(int id, float posX, float posY);
		// -- 拖尾
		void setFirePro_tailPro_isActive(int id, bool isActive);
		void setFirePro_tailPro(int id, std::string tailName, float fade, float minSeg, float stroke, float color_r, float color_g, float color_b);

		emitterVarietyValue* getVarietyValueByType(emitterFirePro* firePro, std::string type);

		// 其他属性
		void setFirePro_varietyValue(int id, std::string valueType, float value);
		void setFirePro_varietyValue(int id, std::string valueType, float randvalue1, float randvalue2);
		void setFirePro_varietyValue_clear(int id, std::string valueType);
		void setFirepro_varietyValue_pushMoreValue(int id, std::string valueType, float value);
		void setFirePro_varietyValue_pushCurveValue(int id, std::string valueType, float x, float value, float randValue);

		void setFirePro_colorValue(int id, std::string valueType, float color_r, float color_g, float color_b);
		void setFirePro_colorValue(int id, std::string valueType, float randcolor1_r, float randcolor1_g, float randcolor1_b, float randcolor2_r, float randcolor2_g, float randcolor2_b);
		void setFirePro_colorValue_clear(int id, std::string valueType);
		void setFirepro_colorValue_pushMoreValue(int id, std::string valueType, float color_r, float color_g, float color_b);
		void setFirePro_colorValue_pushCurveValue(int id, std::string valueType, float x, float color_r, float color_g, float color_b, float randcolor_r, float randcolor_g, float randcolor_b);

	};
	


}




#endif // !_PARTICLE_EMITTER_H_