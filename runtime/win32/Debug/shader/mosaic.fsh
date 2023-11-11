///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标
///每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;
///C程序中传入的纹理数据
uniform sampler2D Texture;

const float spaceNum = 10.0;

float getSpaceXY(float xy){
	float space = 1.0 / spaceNum;
	
	int num = int(xy / space);
	float xyStart = num * space;
	float xyEnd = (num + 1.0) * space;
	if(xyEnd > 1.0){
		xyEnd = 1.0;
	}
	int randomNum_xy = mod((num * 13 + 7) , 100);
	float tar_xy = xyStart + (randomNum_xy / 100.0) * (xyEnd - xyStart);
	
	return tar_xy;
}

void main()
{
	///首先获得每个像素的颜色
	vec4 v_orColor = texture2D(Texture , vec2(getSpaceXY(v_texCoord.x), getSpaceXY(v_texCoord.y))) * v_fragmentColor;

	///将点乘后的颜色值，给全局gl_FragColor
	gl_FragColor = v_orColor;
}