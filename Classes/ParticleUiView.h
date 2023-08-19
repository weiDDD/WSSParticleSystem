#pragma once

#ifndef _PARTICLE_UI_VIEW_H_
#define _PARTICLE_UI_VIEW_H_

#include "cocos2d.h"
#include "cocostudio\CCSGUIReader.h"
#include "cocos-ext.h"
#include "ui/UITextField.h"
#include "ui/UISlider.h"
#include "ParticleEmitter.h"
#include "DropDownList.h"
#include <iostream>
#include <Windows.h>
#include "shaderSprite.h"

using namespace std;
using namespace pp;

#define LINE_COLOR_7 Color3B(255,0,0)
#define LINE_COLOR_6 Color3B(255,0,255)
#define LINE_COLOR_5 Color3B(0,0,255)
#define LINE_COLOR_4 Color3B(0,255,255)
#define LINE_COLOR_3 Color3B(0,255,0)
#define LINE_COLOR_2 Color3B(255,255,0)
#define LINE_COLOR_1 Color3B(255,0,0)


USING_NS_CC;
//USING_NS_CC_EXT;
using namespace cocostudio;
using namespace ui;

typedef extension::EditBox ExEditBox;
typedef extension::ControlSlider ExSlider;

// ui编辑模式
enum EditMode {
	single,
	more
};

// 单一粒子编辑模式中，属性类型
enum singleProType {
	singleProTypeNone = 0,
	///// 粒子发射时属性类型
	life_fireStart = 1,
	speed_fireStart = 2,
	acc_fireStart = 3,
	moveAngle_fireStart = 4,
	moveAngleSpeed_fireStart = 5,
	gravityX_fireStart = 6,
	gravityY_fireStart = 7,
	size_fireStart = 8,
	rotation_fireStart = 9,
	rotationSpeed_fireStart = 10,
	skewX_fireStart = 11,
	skewXSpeed_fireStart = 12,
	skewY_fireStart = 13,
	skewYSpeed_fireStart = 14,
	alpha_fireStart = 15,
	color_fireStart = 16,
	///// 粒子生命周期内属性类型
	speed_parLife = 17,
	acc_parLife = 18,
	moveAngle_parLife = 19,
	moveAngleSpeed_parLife = 20,
	gravityX_parLife = 21,
	gravityY_parLife = 22,
	size_parLife = 23,
	rotation_parLife = 24,
	rotationSpeed_parLife = 25,
	skewX_parLife = 26,
	skewXSpeed_parLife = 27,
	skewY_parLife = 28,
	skewYSpeed_parLife = 29,
	alpha_parLife = 30,
	color_parLife = 31,
};

static std::string singleProTypeString[32] = {"none","生命","速度","加速度","移动角度","角速度","重力X","重力Y","大小","旋转角度","旋转速度","倾斜角X","倾斜角X速度","倾斜角Y","倾斜角Y速度","不透明度","颜色",
												"速度","加速度","移动角度","角速度","重力X","重力Y","大小","旋转角度","旋转速度","倾斜角X","倾斜角X速度","倾斜角Y","倾斜角Y速度","不透明度","颜色" };

class ParticleUiView : public Layer, public extension::EditBoxDelegate
{
public:
	ParticleUiView();
	~ParticleUiView(); 

	static ParticleUiView* create();

	virtual bool init();
	virtual void update(float dt);

	void initUi();

	// 组合粒子面板
	void initMoreParPanel();
	// 加一个到组合粒子的面板中
	Widget* addOneToMoreParPanel(std::string showWord, std::string tagName, int id , int localZorder);
	// 清理
	void clearMoreParPanel();

	std::vector<Widget*> moreParWidgetVec;

	///////触摸事件
	virtual bool onTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);

	////editBox改变的回调函数
	void editBoxEditingDidBegin(ExEditBox* editBox);
	void editBoxEditingDidEnd(ExEditBox* editBox);
	void editBoxTextChanged(ExEditBox* editBox, const std::string& text);
	void editBoxReturn(ExEditBox* editBox);
	////当下拉列表选中时de回调函数
	void onDropDownList(Object* list, ui::Widget::TouchEventType type, DropDownList* sender);
	////////各滑动条的改变回调函数
	void onSliderChanged(Ref* sender, extension::Control::EventType);
	////单选 ，按钮 回调函数
	void checkBoxEvent(Ref* pSender, ui::CheckBox::EventType type);

	// 设置一个滑动条的值，判断值是否大于滑动条的最大或最小
	void setSliderValueWithMaxMin(ExSlider& slider , float value);

	void setSliderValueWithMaxMinNoSetValueEvent(ExSlider& slider, float value);

	// 显示添加firePro的面板
	void showAddFireProPanel();
	// 隐藏 添加firePro的面板
	void hideAddFireProPanel();
	bool isOpenAddFireProPanel = false;

	//////添加文件的面板
	// 显示添加 file 的面板
	void showAddFilePanel();
	// 隐藏 添加 file 的面板
	void hideAddFilePanel();
	bool isOpenAddFilePanel = false;

	// 将UI节点中的 TextField 缓存EditBox , Slider 换成 ControlSlider
	void replaceTextFieldToEditBox(Widget* rootNode);  

	// 读texture纹理文件夹	////获取指定文件夹下的.png文件
	std::vector<std::string> getPngFileName();
	// 读json文件夹	////获取指定文件夹下的.par文件
	std::vector<std::string> getJsonFileName();
	// 读refSprite文件夹	////获取指定文件夹下的.png文件
	std::vector<std::string> getRefSpriteName();
	// 读tail文件夹	////获取指定文件夹下的.png文件
	std::vector<std::string> getTailSpriteName();
	// 读shader文件夹	////获取指定文件夹下的.vsh文件
	std::vector<std::string> getShaderName();

	// 搜索定位一个节点下名为 xxx 的节点
	Widget* seekByName(Widget* rootNode , std::string name);

	// 显示和隐藏 发射时粒子属性的值编辑面板 , isInitValue是否使用当前在编辑的功能初始化界面
	void showFireStartProValuePanel(singleProType proType, emitterPropertyType type , bool isInitValue = false);
	void hideFireStartProValuePanel();

	

	// 显示和隐藏 粒子生命周期 属性的值编辑面板
	void showParLifeProValuePanel(singleProType proType);
	void hideParLifeProValuePanel();

	// 设置 拖尾属性面板是否 显示 或 隐藏
	void setTailProPanelVisible(bool visible);

	// 设置发射属性面板的层的隐藏和显示
	void setFireProLayerVisible(bool visible);

	// 根据 当前正在编辑的单粒子属性 来初始化 单粒子编辑的ui
	void initSingleParUi();

	emitterFirePro* getNowEditingSignalPar() { return nowEditingSignalPar; }
	void setNowEditingSignalPar(emitterFirePro* firePro) { nowEditingSignalPar = firePro; }
	pp::ParticleEmitter* getSignalPar() { return singlePar; }

	//************************************ 发射区域 相关*****************************
	// 设置 发射区域模式
	void setFireAreaMode(varietyFireAreaValue& areaData);

	// 显示 发射区域点 , 多边形和线段的 , 当开启自定义编辑时，将 发射区域点数据 转换成 点按钮
	void showDiyFireAreaPoint();
	// 隐藏 发射区域点
	void hideDiyFireAreaPoint();
	//发射区域点 按钮 的回调函数
	void diyFireAreaPointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);
	// 当前选中的 自定义的 发射区域的 按钮
	ui::Button* targetdiyFireAreaPointBtn = nullptr;

	// 当 点按钮移动时更新
	void refreshDiyFireAreaPoints();
	// 新增一个 发射区域点 , 对于 多边形发射区域，在其边上点击时，增加一个边的截断点；对于线段发射区域，一只都是在末尾增加点
	void addDiyFireAreaPoint(Vec2 pos);
	// 删除一个点
	void deleteDiyFireAreaPoint( ui::Button* btn );

private:
	// 是否开始删除 自定义 发射区域的点按钮 
	bool isStartDeleteDiyFireAreaPointBtn;
	// 删除需要的时间
	float deleteDiyFireAreaPointNeedTime;
	float deleteDiyFireAreaPointNeedTimeCount;
	//*****************************************************************

public:
	// *********** 多个常量值 相关
	// 显示多个常值的ui列表
	void showMoreConstantWidgetVec(std::vector<float>& vec);
	void hideMoreConstantWidgetVec();
	void addMoreConstantWidgetVec(float value);

	// ***************************** 发射时粒子属性的 曲线数据 相关 *****************************
	void showFireStartCurvePoints();
	void hideFireStartCurvePoints();
	void addFireStartCurvePoints(Vec2 pos);
	void deleteFireStartCurvePoints(ui::Button* btn);
	// 是否打开了 发射时属性 的曲线编辑面板
	bool isOpenFireStartCurvePanel;
	// 刷新 点 和 线 ，参数:最大的纵坐标
	void refreshFireStartCurvePoints(float maxHeight);

	// 最大的纵坐标
	float fireStartCurvePointMaxHeight;

	std::vector<ui::Button*> fireStartCurvePointBtnVec; // 点 按钮的集合
	std::vector<Sprite*> fireStartCurveLines;           // 连接点 按钮的线的集合
	std::vector<ExEditBox*> fireStartCurveRandEditBoxVec; // 每个点的y 坐标的随机值 输入框
	std::vector<Sprite*> fireStartCurveRandLines;         // 连接 随机值 输入框 的线的集合

	// 发射时属性 的 曲线点 按钮 的回调函数
	void fireStartCurvePointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);
	// 当前选中的 发射时属性 的 曲线点 按钮
	ui::Button* targetFireStartCurvePointBtn = nullptr;
	ui::Button* targetFireStartCurvePointBtn_left = nullptr;
	ui::Button* targetFireStartCurvePointBtn_right = nullptr;
	// bool 是否开始删除这个  开始发射 时曲线属性的点
	bool isStartDeleteFireStartCurvePointBtn;
	// 删除需要的时间
	float deleteFireStartCurvePointNeedTime;
	float deleteFireStartCurvePointNeedTimeCount;

	// ***************************** 粒子生命周期内属性的 曲线数据 相关 *****************************
	
	void showParLifeCurvePoints();                     // 显示
	void hideParLifeCurvePoints();                     // 隐藏
	void addParLifeCurvePoints(Vec2 pos);              // 新增
	void deleteParLifeCurvePoints(ui::Button* btn);    // 删除
	void refreshParLifeCurvePoints(float maxHeight); // 刷新 点 和 线 ，参数:最大的纵坐标

	// 是否打开了 粒子生命周期内属性 的曲线编辑面板
	bool isOpenParLifeCurvePanel;
	// 最大的纵坐标
	float parLifeCurvePointMaxHeight;
	// 左边的横坐标 ----  这里的很坐标是相对于粒子整个生命的百分比， 0 < n < 100
	float parLifeCurvePointLeftPrecent;
	float parLifeCurvePointRightPrecent;

	std::vector<ui::Button*> parLifeCurvePointBtnVec; // 点 按钮的集合
	std::vector<Sprite*> parLifeCurveLines;           // 连接点 按钮的线的集合
	std::vector<ExEditBox*> parLifeCurveRandEditBoxVec; // 每个点的y 坐标的随机值 输入框
	std::vector<Sprite*> parLifeCurveRandLines;         // 连接 随机值 输入框 的线的集合

	// 粒子生命周期 属性 的 曲线点 按钮 的回调函数
	void parLifeCurvePointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// 当前选中的 粒子生命周期 的 曲线点 按钮
	ui::Button* targetParLifeCurvePointBtn = nullptr;
	ui::Button* targetParLifeCurvePointBtn_left = nullptr;
	ui::Button* targetParLifeCurvePointBtn_right = nullptr;
	// bool 是否开始删除这个  开始发射 时曲线属性的点
	bool isStartDeleteParLifeCurvePointBtn;
	// 删除需要的时间
	float deleteParLifeCurvePointNeedTime;
	float deleteParLifeCurvePointNeedTimeCount;

	// **************************** 颜色 相关 *****************************
	// 显示和隐藏 发射时粒子 颜色 属性的值编辑面板 
	void showFireStartProColorValuePanel(singleProType proType, emitterPropertyType type, bool isInitValue = false);
	void hideFireStartProColorValuePanel();
	void refreshFireStartProColorValuePanel();
	// 显示，隐藏设置颜色面板
	void showSetColorPanel(bool isShowRandColor = false);
	void hideSetColorPanel();
	

	bool isOpenSetColorPanel;

	ShaderSprite* colorRect;
	ShaderSprite* colorLine;
	ShaderSprite* randColorLine;
	ShaderSprite* fireStartCurveColorLine;
	ShaderSprite* parLifeCurveColorLine;

	// 这两个值用Color3B数据会出错
	Vec3 rectColor = Vec3(255,255,255);
	Vec3 lineColor = Vec3(255,0,0);

	// 参数:指针在 colorLine 图片上的y坐标,colorLine的锚点为0,0
	void setLineColor(float posY);
	// 参数:指针在 colorRect 图片上的坐标,colorRect的锚点为0,0
	void setRectColor(Vec2 pos , Color3B* realColor = nullptr);

	// 根据输入的rgb值来设置 rectPointer 和 linePointer 的位置
	void setPointerPosByRGB(Color3B color);

	bool isTouchInColorRect;
	bool isTouchInColorLine;
	bool isTouchInColorPanelMoveBar;
	Vec2 touchMoveBarOffsetPos;
	// 当前正在编辑的颜色的显示按钮
	Widget* nowEditingColorNode;
	// 当前正在编辑的曲线颜色数据 的 一个点
	colorCurvePoint* nowEditingColorPoint;

	////----------------------------------------------------------------- 多个颜色之中的随机颜色
	void showMoreColorWidgetVec(std::vector<Color3B>& vec);
	void hideMoreColorWidgetVec();
	void addMoreColorWidgetVec(Color3B color);

	////------------------------------------------------------------------- 发射周期中的 曲线颜色
	// 是否打开了 发射时 “颜色” 属性 的曲线编辑面板
	bool isOpenFireStartCurveColorPanel;
	
	void showFireStartCurveColors();
	void hideFireStartCurveColors();
	void addFireStartCurveColors(float posX);    // 参数;触摸点的X位置
	void deleteFireStartCurveColors(ui::Button* btn);
	void refreshFireStartCurveColors();  // 刷新 颜色条

	std::vector<ui::Button*> fireStartCurveColorBtnVec; // 颜色点 按钮的集合

	// 发射时属性 的 颜色 曲线点 按钮 的回调函数
	void fireStartCurveColorCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// 当前选中的 发射时属性 的 曲线点 按钮
	ui::Button* targetFireStartCurveColorBtn = nullptr;
	// bool 是否开始删除这个  开始发射 时曲线属性的点
	bool isStartDeleteFireStartCurveColorBtn;
	// 删除需要的时间
	float deleteFireStartCurveColorNeedTime;
	float deleteFireStartCurveColorNeedTimeCount;

	////--------------------------------------------------------------------- 粒子生命周期内的 曲线颜色
	// 是否打开了 粒子生命周期内 “颜色” 属性 的曲线编辑面板
	bool isOpenParLifeCurveColorPanel;

	void showParLifeCurveColors();
	void hideParLifeCurveColors();
	void addParLifeCurveColors(float posX);    // 参数;触摸点的X位置
	void deleteParLifeCurveColors(ui::Button* btn);
	void refreshParLifeCurveColors();  // 刷新 颜色条

	std::vector<ui::Button*> parLifeCurveColorBtnVec; // 颜色点 按钮的集合

														// 粒子生命周期内 的 颜色 曲线点 按钮 的回调函数
	void parLifeCurveColorCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// 左边的横坐标 ----  这里的很坐标是相对于粒子整个生命的百分比， 0 < n < 100
	float parLifeCurveColorLeftPrecent;
	float parLifeCurveColorRightPrecent;

	// 当前选中的 发射时属性 的 曲线点 按钮
	ui::Button* targetParLifeCurveColorBtn = nullptr;
	// bool 是否开始删除这个 
	bool isStartDeleteParLifeCurveColorBtn;
	// 删除需要的时间
	float deleteParLifeCurveColorNeedTime;
	float deleteParLifeCurveColorNeedTimeCount;

private:
	// 运行的时间
	float nowTime;
	float lastTouchTime;     // 上一次触摸的时间
	float lastTouchDelay;    // 上一次触摸的延迟时间，上一次点击后，在这个时间内不能点击

	Sprite* refSprite;     // 参考图片

	std::string nowFileName = "";

	// 纹理文件的vector
	std::vector<std::string> texNames;

	// 资源文件的vector
	std::vector<std::string> fileNames;

	// 参考图片的vector
	std::vector<std::string> refSpriteNames;

	// 拖尾图片的vector
	std::vector<std::string> tailSpriteNames;

	// shader 的vector
	std::vector<std::string> shaderNames;

	// 纹理下拉框
	DropDownList* textureList;

	// 单粒子 json文件 下拉框
	DropDownList* jsonFileList;

	// 新增子粒子发射器 的文件下拉
	DropDownList* addFireProjsonFileList;

	std::vector<std::string> addFireProJsonfileNames;
	std::string nowAddFireProJsonFileName = "";

	// 参考图片的下拉框
	DropDownList* refSpriteList;

	// 拖尾图片的下拉框
	DropDownList* tailSpriteList;

	DropDownList* shaderList;

	// 编辑模式
	EditMode editMode;
	// 主菜单面板
	Widget* mainRootNode;
	// 编辑单一粒子属性的面板
	Widget* singleRootNode;

	// 渲染模式
	CheckBox* chkBoxRenderModeLine;
	CheckBox* chkBoxRenderModeTri;
	CheckBox* chkBoxRenderModeTriStrip;

	// 源混合模式的下拉列表
	DropDownList* sourceBlend;
	DropDownList* destBlend;
	DropDownList* fireAreaMode;
	DropDownList* fireStartProValueType;

	// 当前操作的 单一粒子的 哪个属性
	singleProType nowSelectedSingleProType;
	std::string nowSelectedSingleProTypeStr;

	// 发射开始时属性 类型按钮map
	std::map<std::string, singleProType > fireStartProTypeBtns;
	// 粒子生命周期属性 类型map
	std::map<std::string, singleProType > parLifeProTypeBtns;

	// 单粒子编辑面板 的 拖尾属性面板 是否打开
	bool isSingleModeTailPanelOpen;
	// 单粒子编辑面板 的 发射器属性面板是否打开
	bool isSingleModeFireProLayerOpen;
	// 单粒子编辑面板 的 发射开始粒子属性面板是否打开
	bool isSingleModeFireStartProPanelOpen;
	// 单粒子编辑面板 的 粒子生命周期内属性面板是否打开
	bool isSingleModeParLifeProPanelOpen;

	// 当前正在编辑的单一粒子的 发射属性
	emitterFirePro* nowEditingSignalPar;
	// 当前正在编辑的 一个 多样值的属性,比如发射开始的生命值，比如生命周期中的速度...
	emitterVarietyValue* nowEditingEmitterVarietyValue;
	// 当前正在编辑的 颜色 值属性
	emitterColorValue* nowEditingEmitterColorValue;

	// 单粒子发射器 ， 在单粒子编辑模式下使用
	pp::ParticleEmitter* singlePar;

	// 是否正在 自定义 编辑 多边形 或 线条 发射区域
	bool isDiyEditPolygonOrLines;
	// 发射区域 diy 的按钮 vec
	std::vector<ui::Button*> diyFireAreaPointVec;

	// 多个常量属性 的 widget 列表
	std::vector<Widget*> moreConstantWidgetVec;

	// 多个颜色属性 的 widget 列表
	// 多个常量属性 的 widget 列表
	std::vector<Widget*> moreColorWidgetVec;


	// add file firePro 提示text
	ui::Text* addEmitterHintText ;
	// add file 提示 text
	ui::Text* addFileHintText;

};


#endif // !_PARTICLE_UI_VIEW_H_
