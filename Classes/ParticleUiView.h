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

// ui�༭ģʽ
enum EditMode {
	single,
	more
};

// ��һ���ӱ༭ģʽ�У���������
enum singleProType {
	singleProTypeNone = 0,
	///// ���ӷ���ʱ��������
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
	///// ����������������������
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

static std::string singleProTypeString[32] = {"none","����","�ٶ�","���ٶ�","�ƶ��Ƕ�","���ٶ�","����X","����Y","��С","��ת�Ƕ�","��ת�ٶ�","��б��X","��б��X�ٶ�","��б��Y","��б��Y�ٶ�","��͸����","��ɫ",
												"�ٶ�","���ٶ�","�ƶ��Ƕ�","���ٶ�","����X","����Y","��С","��ת�Ƕ�","��ת�ٶ�","��б��X","��б��X�ٶ�","��б��Y","��б��Y�ٶ�","��͸����","��ɫ" };

class ParticleUiView : public Layer, public extension::EditBoxDelegate
{
public:
	ParticleUiView();
	~ParticleUiView(); 

	static ParticleUiView* create();

	virtual bool init();
	virtual void update(float dt);

	void initUi();

	// ����������
	void initMoreParPanel();
	// ��һ����������ӵ������
	Widget* addOneToMoreParPanel(std::string showWord, std::string tagName, int id , int localZorder);
	// ����
	void clearMoreParPanel();

	std::vector<Widget*> moreParWidgetVec;

	///////�����¼�
	virtual bool onTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void onTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);

	////editBox�ı�Ļص�����
	void editBoxEditingDidBegin(ExEditBox* editBox);
	void editBoxEditingDidEnd(ExEditBox* editBox);
	void editBoxTextChanged(ExEditBox* editBox, const std::string& text);
	void editBoxReturn(ExEditBox* editBox);
	////�������б�ѡ��ʱde�ص�����
	void onDropDownList(Object* list, ui::Widget::TouchEventType type, DropDownList* sender);
	////////���������ĸı�ص�����
	void onSliderChanged(Ref* sender, extension::Control::EventType);
	////��ѡ ����ť �ص�����
	void checkBoxEvent(Ref* pSender, ui::CheckBox::EventType type);

	// ����һ����������ֵ���ж�ֵ�Ƿ���ڻ�������������С
	void setSliderValueWithMaxMin(ExSlider& slider , float value);

	void setSliderValueWithMaxMinNoSetValueEvent(ExSlider& slider, float value);

	// ��ʾ���firePro�����
	void showAddFireProPanel();
	// ���� ���firePro�����
	void hideAddFireProPanel();
	bool isOpenAddFireProPanel = false;

	//////����ļ������
	// ��ʾ��� file �����
	void showAddFilePanel();
	// ���� ��� file �����
	void hideAddFilePanel();
	bool isOpenAddFilePanel = false;

	// ��UI�ڵ��е� TextField ����EditBox , Slider ���� ControlSlider
	void replaceTextFieldToEditBox(Widget* rootNode);  

	// ��texture�����ļ���	////��ȡָ���ļ����µ�.png�ļ�
	std::vector<std::string> getPngFileName();
	// ��json�ļ���	////��ȡָ���ļ����µ�.par�ļ�
	std::vector<std::string> getJsonFileName();
	// ��refSprite�ļ���	////��ȡָ���ļ����µ�.png�ļ�
	std::vector<std::string> getRefSpriteName();
	// ��tail�ļ���	////��ȡָ���ļ����µ�.png�ļ�
	std::vector<std::string> getTailSpriteName();
	// ��shader�ļ���	////��ȡָ���ļ����µ�.vsh�ļ�
	std::vector<std::string> getShaderName();

	// ������λһ���ڵ�����Ϊ xxx �Ľڵ�
	Widget* seekByName(Widget* rootNode , std::string name);

	// ��ʾ������ ����ʱ�������Ե�ֵ�༭��� , isInitValue�Ƿ�ʹ�õ�ǰ�ڱ༭�Ĺ��ܳ�ʼ������
	void showFireStartProValuePanel(singleProType proType, emitterPropertyType type , bool isInitValue = false);
	void hideFireStartProValuePanel();

	

	// ��ʾ������ ������������ ���Ե�ֵ�༭���
	void showParLifeProValuePanel(singleProType proType);
	void hideParLifeProValuePanel();

	// ���� ��β��������Ƿ� ��ʾ �� ����
	void setTailProPanelVisible(bool visible);

	// ���÷����������Ĳ�����غ���ʾ
	void setFireProLayerVisible(bool visible);

	// ���� ��ǰ���ڱ༭�ĵ��������� ����ʼ�� �����ӱ༭��ui
	void initSingleParUi();

	emitterFirePro* getNowEditingSignalPar() { return nowEditingSignalPar; }
	void setNowEditingSignalPar(emitterFirePro* firePro) { nowEditingSignalPar = firePro; }
	pp::ParticleEmitter* getSignalPar() { return singlePar; }

	//************************************ �������� ���*****************************
	// ���� ��������ģʽ
	void setFireAreaMode(varietyFireAreaValue& areaData);

	// ��ʾ ��������� , ����κ��߶ε� , �������Զ���༭ʱ���� ������������� ת���� �㰴ť
	void showDiyFireAreaPoint();
	// ���� ���������
	void hideDiyFireAreaPoint();
	//��������� ��ť �Ļص�����
	void diyFireAreaPointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);
	// ��ǰѡ�е� �Զ���� ��������� ��ť
	ui::Button* targetdiyFireAreaPointBtn = nullptr;

	// �� �㰴ť�ƶ�ʱ����
	void refreshDiyFireAreaPoints();
	// ����һ�� ��������� , ���� ����η�������������ϵ��ʱ������һ���ߵĽضϵ㣻�����߶η�������һֻ������ĩβ���ӵ�
	void addDiyFireAreaPoint(Vec2 pos);
	// ɾ��һ����
	void deleteDiyFireAreaPoint( ui::Button* btn );

private:
	// �Ƿ�ʼɾ�� �Զ��� ��������ĵ㰴ť 
	bool isStartDeleteDiyFireAreaPointBtn;
	// ɾ����Ҫ��ʱ��
	float deleteDiyFireAreaPointNeedTime;
	float deleteDiyFireAreaPointNeedTimeCount;
	//*****************************************************************

public:
	// *********** �������ֵ ���
	// ��ʾ�����ֵ��ui�б�
	void showMoreConstantWidgetVec(std::vector<float>& vec);
	void hideMoreConstantWidgetVec();
	void addMoreConstantWidgetVec(float value);

	// ***************************** ����ʱ�������Ե� �������� ��� *****************************
	void showFireStartCurvePoints();
	void hideFireStartCurvePoints();
	void addFireStartCurvePoints(Vec2 pos);
	void deleteFireStartCurvePoints(ui::Button* btn);
	// �Ƿ���� ����ʱ���� �����߱༭���
	bool isOpenFireStartCurvePanel;
	// ˢ�� �� �� �� ������:����������
	void refreshFireStartCurvePoints(float maxHeight);

	// ����������
	float fireStartCurvePointMaxHeight;

	std::vector<ui::Button*> fireStartCurvePointBtnVec; // �� ��ť�ļ���
	std::vector<Sprite*> fireStartCurveLines;           // ���ӵ� ��ť���ߵļ���
	std::vector<ExEditBox*> fireStartCurveRandEditBoxVec; // ÿ�����y ��������ֵ �����
	std::vector<Sprite*> fireStartCurveRandLines;         // ���� ���ֵ ����� ���ߵļ���

	// ����ʱ���� �� ���ߵ� ��ť �Ļص�����
	void fireStartCurvePointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);
	// ��ǰѡ�е� ����ʱ���� �� ���ߵ� ��ť
	ui::Button* targetFireStartCurvePointBtn = nullptr;
	ui::Button* targetFireStartCurvePointBtn_left = nullptr;
	ui::Button* targetFireStartCurvePointBtn_right = nullptr;
	// bool �Ƿ�ʼɾ�����  ��ʼ���� ʱ�������Եĵ�
	bool isStartDeleteFireStartCurvePointBtn;
	// ɾ����Ҫ��ʱ��
	float deleteFireStartCurvePointNeedTime;
	float deleteFireStartCurvePointNeedTimeCount;

	// ***************************** �����������������Ե� �������� ��� *****************************
	
	void showParLifeCurvePoints();                     // ��ʾ
	void hideParLifeCurvePoints();                     // ����
	void addParLifeCurvePoints(Vec2 pos);              // ����
	void deleteParLifeCurvePoints(ui::Button* btn);    // ɾ��
	void refreshParLifeCurvePoints(float maxHeight); // ˢ�� �� �� �� ������:����������

	// �Ƿ���� ������������������ �����߱༭���
	bool isOpenParLifeCurvePanel;
	// ����������
	float parLifeCurvePointMaxHeight;
	// ��ߵĺ����� ----  ����ĺ�������������������������İٷֱȣ� 0 < n < 100
	float parLifeCurvePointLeftPrecent;
	float parLifeCurvePointRightPrecent;

	std::vector<ui::Button*> parLifeCurvePointBtnVec; // �� ��ť�ļ���
	std::vector<Sprite*> parLifeCurveLines;           // ���ӵ� ��ť���ߵļ���
	std::vector<ExEditBox*> parLifeCurveRandEditBoxVec; // ÿ�����y ��������ֵ �����
	std::vector<Sprite*> parLifeCurveRandLines;         // ���� ���ֵ ����� ���ߵļ���

	// ������������ ���� �� ���ߵ� ��ť �Ļص�����
	void parLifeCurvePointCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// ��ǰѡ�е� ������������ �� ���ߵ� ��ť
	ui::Button* targetParLifeCurvePointBtn = nullptr;
	ui::Button* targetParLifeCurvePointBtn_left = nullptr;
	ui::Button* targetParLifeCurvePointBtn_right = nullptr;
	// bool �Ƿ�ʼɾ�����  ��ʼ���� ʱ�������Եĵ�
	bool isStartDeleteParLifeCurvePointBtn;
	// ɾ����Ҫ��ʱ��
	float deleteParLifeCurvePointNeedTime;
	float deleteParLifeCurvePointNeedTimeCount;

	// **************************** ��ɫ ��� *****************************
	// ��ʾ������ ����ʱ���� ��ɫ ���Ե�ֵ�༭��� 
	void showFireStartProColorValuePanel(singleProType proType, emitterPropertyType type, bool isInitValue = false);
	void hideFireStartProColorValuePanel();
	void refreshFireStartProColorValuePanel();
	// ��ʾ������������ɫ���
	void showSetColorPanel(bool isShowRandColor = false);
	void hideSetColorPanel();
	

	bool isOpenSetColorPanel;

	ShaderSprite* colorRect;
	ShaderSprite* colorLine;
	ShaderSprite* randColorLine;
	ShaderSprite* fireStartCurveColorLine;
	ShaderSprite* parLifeCurveColorLine;

	// ������ֵ��Color3B���ݻ����
	Vec3 rectColor = Vec3(255,255,255);
	Vec3 lineColor = Vec3(255,0,0);

	// ����:ָ���� colorLine ͼƬ�ϵ�y����,colorLine��ê��Ϊ0,0
	void setLineColor(float posY);
	// ����:ָ���� colorRect ͼƬ�ϵ�����,colorRect��ê��Ϊ0,0
	void setRectColor(Vec2 pos , Color3B* realColor = nullptr);

	// ���������rgbֵ������ rectPointer �� linePointer ��λ��
	void setPointerPosByRGB(Color3B color);

	bool isTouchInColorRect;
	bool isTouchInColorLine;
	bool isTouchInColorPanelMoveBar;
	Vec2 touchMoveBarOffsetPos;
	// ��ǰ���ڱ༭����ɫ����ʾ��ť
	Widget* nowEditingColorNode;
	// ��ǰ���ڱ༭��������ɫ���� �� һ����
	colorCurvePoint* nowEditingColorPoint;

	////----------------------------------------------------------------- �����ɫ֮�е������ɫ
	void showMoreColorWidgetVec(std::vector<Color3B>& vec);
	void hideMoreColorWidgetVec();
	void addMoreColorWidgetVec(Color3B color);

	////------------------------------------------------------------------- ���������е� ������ɫ
	// �Ƿ���� ����ʱ ����ɫ�� ���� �����߱༭���
	bool isOpenFireStartCurveColorPanel;
	
	void showFireStartCurveColors();
	void hideFireStartCurveColors();
	void addFireStartCurveColors(float posX);    // ����;�������Xλ��
	void deleteFireStartCurveColors(ui::Button* btn);
	void refreshFireStartCurveColors();  // ˢ�� ��ɫ��

	std::vector<ui::Button*> fireStartCurveColorBtnVec; // ��ɫ�� ��ť�ļ���

	// ����ʱ���� �� ��ɫ ���ߵ� ��ť �Ļص�����
	void fireStartCurveColorCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// ��ǰѡ�е� ����ʱ���� �� ���ߵ� ��ť
	ui::Button* targetFireStartCurveColorBtn = nullptr;
	// bool �Ƿ�ʼɾ�����  ��ʼ���� ʱ�������Եĵ�
	bool isStartDeleteFireStartCurveColorBtn;
	// ɾ����Ҫ��ʱ��
	float deleteFireStartCurveColorNeedTime;
	float deleteFireStartCurveColorNeedTimeCount;

	////--------------------------------------------------------------------- �������������ڵ� ������ɫ
	// �Ƿ���� �������������� ����ɫ�� ���� �����߱༭���
	bool isOpenParLifeCurveColorPanel;

	void showParLifeCurveColors();
	void hideParLifeCurveColors();
	void addParLifeCurveColors(float posX);    // ����;�������Xλ��
	void deleteParLifeCurveColors(ui::Button* btn);
	void refreshParLifeCurveColors();  // ˢ�� ��ɫ��

	std::vector<ui::Button*> parLifeCurveColorBtnVec; // ��ɫ�� ��ť�ļ���

														// �������������� �� ��ɫ ���ߵ� ��ť �Ļص�����
	void parLifeCurveColorCall(cocos2d::Ref* pSender, ui::Widget::TouchEventType type);

	// ��ߵĺ����� ----  ����ĺ�������������������������İٷֱȣ� 0 < n < 100
	float parLifeCurveColorLeftPrecent;
	float parLifeCurveColorRightPrecent;

	// ��ǰѡ�е� ����ʱ���� �� ���ߵ� ��ť
	ui::Button* targetParLifeCurveColorBtn = nullptr;
	// bool �Ƿ�ʼɾ����� 
	bool isStartDeleteParLifeCurveColorBtn;
	// ɾ����Ҫ��ʱ��
	float deleteParLifeCurveColorNeedTime;
	float deleteParLifeCurveColorNeedTimeCount;

private:
	// ���е�ʱ��
	float nowTime;
	float lastTouchTime;     // ��һ�δ�����ʱ��
	float lastTouchDelay;    // ��һ�δ������ӳ�ʱ�䣬��һ�ε���������ʱ���ڲ��ܵ��

	Sprite* refSprite;     // �ο�ͼƬ

	std::string nowFileName = "";

	// �����ļ���vector
	std::vector<std::string> texNames;

	// ��Դ�ļ���vector
	std::vector<std::string> fileNames;

	// �ο�ͼƬ��vector
	std::vector<std::string> refSpriteNames;

	// ��βͼƬ��vector
	std::vector<std::string> tailSpriteNames;

	// shader ��vector
	std::vector<std::string> shaderNames;

	// ����������
	DropDownList* textureList;

	// ������ json�ļ� ������
	DropDownList* jsonFileList;

	// ���������ӷ����� ���ļ�����
	DropDownList* addFireProjsonFileList;

	std::vector<std::string> addFireProJsonfileNames;
	std::string nowAddFireProJsonFileName = "";

	// �ο�ͼƬ��������
	DropDownList* refSpriteList;

	// ��βͼƬ��������
	DropDownList* tailSpriteList;

	DropDownList* shaderList;

	// �༭ģʽ
	EditMode editMode;
	// ���˵����
	Widget* mainRootNode;
	// �༭��һ�������Ե����
	Widget* singleRootNode;

	// ��Ⱦģʽ
	CheckBox* chkBoxRenderModeLine;
	CheckBox* chkBoxRenderModeTri;
	CheckBox* chkBoxRenderModeTriStrip;

	// Դ���ģʽ�������б�
	DropDownList* sourceBlend;
	DropDownList* destBlend;
	DropDownList* fireAreaMode;
	DropDownList* fireStartProValueType;

	// ��ǰ������ ��һ���ӵ� �ĸ�����
	singleProType nowSelectedSingleProType;
	std::string nowSelectedSingleProTypeStr;

	// ���俪ʼʱ���� ���Ͱ�ťmap
	std::map<std::string, singleProType > fireStartProTypeBtns;
	// ���������������� ����map
	std::map<std::string, singleProType > parLifeProTypeBtns;

	// �����ӱ༭��� �� ��β������� �Ƿ��
	bool isSingleModeTailPanelOpen;
	// �����ӱ༭��� �� ��������������Ƿ��
	bool isSingleModeFireProLayerOpen;
	// �����ӱ༭��� �� ���俪ʼ������������Ƿ��
	bool isSingleModeFireStartProPanelOpen;
	// �����ӱ༭��� �� ����������������������Ƿ��
	bool isSingleModeParLifeProPanelOpen;

	// ��ǰ���ڱ༭�ĵ�һ���ӵ� ��������
	emitterFirePro* nowEditingSignalPar;
	// ��ǰ���ڱ༭�� һ�� ����ֵ������,���緢�俪ʼ������ֵ���������������е��ٶ�...
	emitterVarietyValue* nowEditingEmitterVarietyValue;
	// ��ǰ���ڱ༭�� ��ɫ ֵ����
	emitterColorValue* nowEditingEmitterColorValue;

	// �����ӷ����� �� �ڵ����ӱ༭ģʽ��ʹ��
	pp::ParticleEmitter* singlePar;

	// �Ƿ����� �Զ��� �༭ ����� �� ���� ��������
	bool isDiyEditPolygonOrLines;
	// �������� diy �İ�ť vec
	std::vector<ui::Button*> diyFireAreaPointVec;

	// ����������� �� widget �б�
	std::vector<Widget*> moreConstantWidgetVec;

	// �����ɫ���� �� widget �б�
	// ����������� �� widget �б�
	std::vector<Widget*> moreColorWidgetVec;


	// add file firePro ��ʾtext
	ui::Text* addEmitterHintText ;
	// add file ��ʾ text
	ui::Text* addFileHintText;

};


#endif // !_PARTICLE_UI_VIEW_H_
