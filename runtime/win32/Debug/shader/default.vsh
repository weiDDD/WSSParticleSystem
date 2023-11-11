#ifdef GL_ES
precision mediump float;
#endif

///vsh为顶点shader，每个绘制顶点调用一次

///attribute 类型和 uniform 数据  为外部传入的数据，可以理解为C++程序传入的
attribute vec4 a_position;  ///顶点的位置
attribute vec2 a_texCoord;  ///返回纹理坐标，左上角(0,0)右上角(1,0)...
attribute vec4 a_color;     ///顶点的颜色

///varying类型的数据时用来和fragmentShader碎片shader进行交互的数据
varying vec4 v_fragmentColor;  ///用来捕获顶点颜色
varying vec2 v_texCoord;       ///用来捕获纹理坐标
                                 
void main() 
{
    
    gl_Position = CC_MVPMatrix * a_position;   ///设置全局顶点的位置
	
    v_fragmentColor = a_color;    ///设置将要传出的数据:顶点颜色

	v_texCoord = a_texCoord;     ///设置将要传出的数据:顶点坐标
}