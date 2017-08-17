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

// 传入颜色值
uniform vec3 rightTopColor;

void main()
{
	///首先获得每个像素的颜色
	vec4 v_orColor = v_fragmentColor * texture2D(Texture , v_texCoord);
	
	vec3 nowColorX = vec3( 255.0 + v_texCoord.x * (rightTopColor.x - 255.0) , 255.0 + v_texCoord.x * (rightTopColor.y - 255.0) , 255.0 + v_texCoord.x * (rightTopColor.z - 255.0) );
	vec3 nowColor = vec3( nowColorX.x + v_texCoord.y * (0.0 - nowColorX.x) , nowColorX.y + v_texCoord.y * (0.0 - nowColorX.y), nowColorX.z + v_texCoord.y * (0.0 - nowColorX.z) );
	
	gl_FragColor = vec4(nowColor.x / 255.0 , nowColor.y / 255.0 , nowColor.z / 255.0 ,v_orColor.a);
	
}