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
	if (y > 1.0){
		y = mod(y, 1.0);
	}
	
	gl_FragColor = texture2D(Texture , vec2(v_texCoord.x, y)) * v_fragmentColor;
}