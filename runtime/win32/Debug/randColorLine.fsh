///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用
#ifdef GL_ES
precision mediump float;
#endif

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标
///每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;
///C程序中传入的纹理数据
uniform sampler2D Texture;

uniform vec3 randColorLeft;
uniform vec3 randColorRight;

void main()
{
	///首先获得每个像素的颜色
	vec4 v_orColor = v_fragmentColor * texture2D(Texture , v_texCoord);
	
	vec3 nowColor = vec3( randColorLeft.r + v_texCoord.x * (randColorRight.r - randColorLeft.r),
							randColorLeft.g + v_texCoord.x * (randColorRight.g - randColorLeft.g),
								randColorLeft.b + v_texCoord.x * (randColorRight.b - randColorLeft.b) );
	
	gl_FragColor = vec4(nowColor.x / 255.0 , nowColor.y / 255.0 , nowColor.z / 255.0 ,v_orColor.a);
	
}