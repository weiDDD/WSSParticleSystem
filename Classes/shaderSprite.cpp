#include "shaderSprite.h"
USING_NS_CC;

ShaderSprite::ShaderSprite(){
	texture = nullptr;
}
ShaderSprite::~ShaderSprite(){
	if (texture) {
		texture->release();
	}
}


ShaderSprite* ShaderSprite::create(const std::string& filename){
	ShaderSprite* sprite = new ShaderSprite();
	if (sprite && sprite->initWithFile(filename)){
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

ShaderSprite* ShaderSprite::createWithTexture(CCTexture2D* tex){

	ShaderSprite *sprite = new ShaderSprite();
	Rect rect = Rect::ZERO;
	rect.size = tex->getContentSize();
	if (sprite && sprite->initWithTexture(tex, rect))
	{
		//sprite->init();
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
/////////////////////////


bool ShaderSprite::initWithTexture(CCTexture2D* pTexture, const CCRect& tRect){
	do {
		CC_BREAK_IF(!Sprite::initWithTexture(pTexture, tRect));

		///初始的shader文件和第二个纹理
		//auto pProgram = GLProgram::createWithFilenames("godLight.vsh", "godLight.fsh");

		//tex = Director::getInstance()->getTextureCache()->addImage("frostBg.png")->getName();		

		///创建shaderstate  shader状态
		//auto glprogramstate = GLProgramState::getOrCreateWithGLProgram(pProgram);
		///设置shader
		//setGLProgramState(glprogramstate);

	
		CHECK_GL_ERROR_DEBUG();
		return true;

	} while (0);
	return false; 

	

}



void ShaderSprite::draw(Renderer* renderer, const Mat4 &transform, uint32_t flags){
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(ShaderSprite::onDraw,this,transform,flags);
	renderer->addCommand(&_customCommand);

}

void ShaderSprite::onDraw(const Mat4& transform,uint32_t flags){
	///获取shaderstate
	auto glProgramState = getGLProgramState();

	/////遍历所有的参数map，将其设值
	std::map <std::string, float>::iterator floatItor = floatArgMap.begin();
	while (floatItor != floatArgMap.end()){
		std::string argKeyName = floatItor->first;
		float value = floatItor->second;
		glProgramState->setUniformFloat(argKeyName, value);
		floatItor++;
	}

	std::map <std::string, int>::iterator intItor = intArgMap.begin();
	while (intItor != intArgMap.end()){
		std::string argKeyName = intItor->first;
		int value = intItor->second;
		glProgramState->setUniformInt(argKeyName, value);
		intItor++;
	}

	std::map <std::string, Vec2>::iterator vec2Itor = vec2ArgMap.begin();
	while (vec2Itor != vec2ArgMap.end()){
		std::string argKeyName = vec2Itor->first;
		Vec2 value = vec2Itor->second;
		glProgramState->setUniformVec2(argKeyName, value);
		vec2Itor++;
	}

	std::map <std::string, Vec3>::iterator vec3Itor = vec3ArgMap.begin();
	while (vec3Itor != vec3ArgMap.end()){
		std::string argKeyName = vec3Itor->first;
		Vec3 value = vec3Itor->second;
		glProgramState->setUniformVec3(argKeyName, value);
		vec3Itor++;
	}

	std::map <std::string, Vec4>::iterator vec4Itor = vec4ArgMap.begin();
	while (vec4Itor != vec4ArgMap.end()){
		std::string argKeyName = vec4Itor->first;
		Vec4 value = vec4Itor->second;
		glProgramState->setUniformVec4(argKeyName, value);
		vec4Itor++;
	}

	
	///应用GLProgram,顶点属性和Uniform参数到渲染管线
	glProgramState->apply(transform);

	// 数组 , 这个必须放到apply的后面那个
	std::map <std::string, floatVec>::iterator floatVecItor = floatVecArgMap.begin();
	while (floatVecItor != floatVecArgMap.end()) {
		std::string argKeyName = floatVecItor->first;
		floatVec value = (floatVec)floatVecItor->second;
		GLint loc = glGetUniformLocation(getGLProgram()->getProgram(), argKeyName.c_str()); //glProgramState->getGLProgram()->getUniformLocation(argKeyName);

																							//const float test[5] = { 0.2f,0.4f,0.6f,0.8f,1.0f };
		glUniform1fv(loc, (GLsizei)value.size, (const GLfloat *)value.vec); // 设置1个float类型的v（代表数组）
																			//getGLProgram()->setUniformLocationWith1fv(loc , (const GLfloat*)test , (GLsizei)3);  // setUniformLocationWith1fv
		floatVecItor++;
	}

	///设置混合模式
	GL::blendFunc(_blendFunc.src,_blendFunc.dst);
	//BlendFunc cbl = { GL_ONE, GL_ONE_MINUS_SRC_ALPHA };//我也不知道，何时加了个这个混合模式
	//this->setBlendFunc(cbl);

	GL::bindTexture2D(_texture->getName());
	////激活名字为position,color,texture的vertex attribute
	GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);

	////_quad 数据是在Sprite类的initWithTexture(Texture2D,Rect,bool) 中赋值的

	


#define kQuadSize sizeof(_quad.bl)
	size_t offset = (size_t)&_quad;

	/////下面应该在向顶点shader传递数据
	///vertex
	int diff = offsetof(V3F_C4B_T2F, vertices);
	
	///glVertexAttribPointer为着色器中指定的变量设置每个顶点属性及三个元素的值的取值指针起始位置。
	///参数详解：
	///1.index:      指定要修改的顶点属性的索引值
	///2.size:       指定每个顶点属性的组件数量，如position由（x,y,z）组成则为3，color由（r,g,b,a）组成则为4
	///3.type:       指定数组中每个组件的数据类型，比如position中的x,y,z是什么类型的。
	///4.normalized: 指定当被访问时，固定点数据值应该被归一化(GL_TRUE ) 或直接转换为固定值 (GL_FALSE)
	///5.stride:     指定连续顶点属性之间的偏移量。V3F_C4B_T2F_Quad类型中有4个V3F_C4B_T2F类型的左上，右上，右下，左下，四个顶点的数据，每个V3F_C4B_T2F中又有vertices，color，texcoord数据；！！所以从第一个左上点中的V3F_C4B_T2F中的vertices跳到下一个右上点中的V3F_C4B_T2F中的vertices，间隔为一个V3F_C4B_T2F类型长度
	///6.pointer:    指定第一个组件在数组的第一个顶点属性中的偏移量。应该就是
	///为位置position指定数据源
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));
	///texCoods
	diff = offsetof(V3F_C4B_T2F,texCoords);
	///为纹理(默认纹理) 指定数据源
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

	///多重纹理设置，获取了一个内置的uniform变量，并向其中传入数据。下两行的1代表第二层纹理，0为默认纹理
	GLuint testTexUniform = glGetUniformLocation(getGLProgram()->getProgram() ,"CC_Texture1");
	GL::bindTexture2DN(1,tex);
	glUniform1i(testTexUniform,1);

	///color
	diff = offsetof(V3F_C4B_T2F, colors);
	///为颜色 指定数据源
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));
	//绘制三角形，所谓的draw call就是指这个函数的调用
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	CHECK_GL_ERROR_DEBUG();
	//通知cocos2d-x的render,让它在合适的时候调用这些Opengl命令
	CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 4);


	

}


void ShaderSprite::setFloatArg(std::string argKeyName, float value){
	std::map<std::string, float>::iterator itor = floatArgMap.find(argKeyName);
	///没有找到则新增
	if (itor == floatArgMap.end()){
		floatArgMap.insert( std::make_pair(argKeyName, value) );
	}
	else{
		itor->second = value;
	}
}
void ShaderSprite::setIntArg(std::string argKeyName, int value){
	std::map<std::string, int>::iterator itor = intArgMap.find(argKeyName);
	///没有找到则新增
	if (itor == intArgMap.end()){
		intArgMap.insert(std::make_pair(argKeyName, value));
	}
	else{
		itor->second = value;
	}
}

void ShaderSprite::setVec2Arg(std::string argKeyName, Vec2 value){
	std::map<std::string, Vec2>::iterator itor = vec2ArgMap.find(argKeyName);
	///没有找到则新增
	if (itor == vec2ArgMap.end()){
		vec2ArgMap.insert(std::make_pair(argKeyName, value));
	}
	else{
		itor->second = value;
	}
}

void ShaderSprite::setVec3Arg(std::string argKeyName, Vec3 value){
	std::map<std::string, Vec3>::iterator itor = vec3ArgMap.find(argKeyName);
	///没有找到则新增
	if (itor == vec3ArgMap.end()){
		vec3ArgMap.insert(std::make_pair(argKeyName, value));
	}
	else{
		itor->second = value;
	}
}

void ShaderSprite::setVec4Arg(std::string argKeyName, Vec4 value){
	std::map<std::string, Vec4>::iterator itor = vec4ArgMap.find(argKeyName);
	///没有找到则新增
	if (itor == vec4ArgMap.end()){
		vec4ArgMap.insert(std::make_pair(argKeyName, value));
	}
	else{
		itor->second = value;
	}
}

void ShaderSprite::setIntVecArg(std::string argKeyName, const int* ptr, ssize_t size) {
	std::map<std::string, intVec>::iterator itor = intVecArgMap.find(argKeyName);
	///没有找到则新增,有则修改
	if (itor == intVecArgMap.end()) {
		intVecArgMap.insert(std::make_pair(argKeyName, intVec(ptr, size)));
	}
	else {
		itor->second = intVec(ptr, size);
	}
}

void ShaderSprite::setIntVecArgLua(std::string argKeyName, const cocos2d::ValueVector &ptr, ssize_t size) {
	std::map<std::string, intVec>::iterator itor = intVecArgMap.find(argKeyName);
	///没有找到则新增,有则修改
	//const float* fPtr = (const float*)ptr;
	const ssize_t s = size;
	static int *iVec = new int(s);
	auto vecitor = ptr.begin();
	int index = 0;
	while (vecitor != ptr.end())
	{
		iVec[index] = float(ptr.at(index).asInt());
		index++;
		vecitor++;
	}

	if (itor == intVecArgMap.end()) {
		intVecArgMap.insert(std::make_pair(argKeyName, intVec(&iVec[0], size)));
	}
	else {
		itor->second = intVec(&iVec[0], size);
	}

}

// 
void ShaderSprite::setFloatVecArg(std::string argKeyName, float* ptr, ssize_t size) {
	std::map<std::string, floatVec>::iterator itor = floatVecArgMap.find(argKeyName);
	///没有找到则新增,有则修改
	const float* fPtr = (const float*)ptr;
	if (itor == floatVecArgMap.end()) {
		floatVecArgMap.insert(std::make_pair(argKeyName, floatVec(fPtr,size)));
	}
	else {
		itor->second = floatVec(fPtr, size);
	}

}

void ShaderSprite::setFloatVecArgLua(std::string argKeyName, const cocos2d::ValueVector &ptr, ssize_t size) {
	std::map<std::string, floatVec>::iterator itor = floatVecArgMap.find(argKeyName);
	///没有找到则新增,有则修改
	//const float* fPtr = (const float*)ptr;
	const ssize_t s = size;
	static float *fVec = new float(s);
	auto vecitor = ptr.begin();
	int index = 0;
	while (vecitor != ptr.end())
	{
		fVec[index] = float(ptr.at(index).asDouble());
		index++;
		vecitor++;
	}

	if (itor == floatVecArgMap.end()) {
		floatVecArgMap.insert(std::make_pair(argKeyName, floatVec(&fVec[0], size)));
	}
	else {
		itor->second = floatVec(&fVec[0], size);
	}

}



////哦，好像没用
void ShaderSprite::clearAllArgMap(){
	floatArgMap.clear();    
	intArgMap.clear();
	vec2ArgMap.clear();
	vec3ArgMap.clear();
	vec4ArgMap.clear();
	intVecArgMap.clear();
	floatVecArgMap.clear();
}
