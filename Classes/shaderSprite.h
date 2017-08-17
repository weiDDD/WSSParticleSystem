/*\
	魏世顺

 本类，已经实现，
	1.利用图片的混合模式来达到一定的图片叠加效果
	2.使一张图片变灰，使用的是gray.vsh;gray.fsh
	3.使一张图片改变其HSL值，使其更加的炫酷
	....

*/

#ifndef SHADER_SPEITE_H
#define SHADER_SPRITE_H

#include "cocos2d.h"
USING_NS_CC;

class ShaderSprite : public Sprite{
public:
	ShaderSprite();
	virtual ~ShaderSprite();

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

	static ShaderSprite* create(const std::string& filename);
	static ShaderSprite* createWithTexture(Texture2D* tex);

	bool initWithTexture(Texture2D* pTexture,const CCRect& tRect);
	virtual void draw(Renderer* renderer,const Mat4 &transform,uint32_t flags) override;
	void onDraw(const Mat4& transform,uint32_t flags);
	////
	////设置shader文件
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
	void setIntVecArg(std::string argKeyName,const int* ptr , ssize_t size);
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

	///第二层纹理
	Texture2D* texture;
	GLuint tex;



protected:
	CustomCommand _customCommand;
private:
	
};



#endif