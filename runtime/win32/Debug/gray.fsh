///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标, 每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;

///C程序中传入的纹理数据
uniform sampler2D Texture;

void main()
{
	///首先获得每个像素的颜色
	float y = v_texCoord.y + CC_Time[1];
	if (y > 1){
		y = mod(y, 1);
	}
	
	//float y = v_texCoord.y;
	
	vec4 v_orColor = texture2D(Texture , vec2(v_texCoord.x, y));
	
	///然后把这个颜色的rgb点乘上 vec3(0.3, 0.59, 0.11)
	vec3 grayVec = vec3(0.5, 0.5, 0.5);
	float grayVecLen = length(grayVec);
	float gray = dot(v_orColor.rgb, grayVec) / grayVecLen;
	
	///将点乘后的颜色值，给全局 gl_FragColor
	gl_FragColor = vec4(gray,gray,gray,v_orColor.a);
	
	// 使用顶点颜色
	//gl_FragColor = v_fragmentColor;
}