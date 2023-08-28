///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标
///每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;
///C程序中传入的纹理数据
//uniform sampler2D Texture;

const float outlineSize = 0.03;  ///描边线的宽度
const vec3 outlineColor = vec3(0.5, 0.6, 0.0);  ///描边颜色

///找到了几个满足条件的角度
float findNum = 0.0;
float getIsStrokeWithAngel(float angle){
	float stroke = 0.0;
	float rad = angle * 0.01745329252;
	float a = texture2D(CC_Texture0,vec2(v_texCoord.x + outlineSize * cos(rad), v_texCoord.y + outlineSize * sin(rad) )).a;
	///距离，返回距离
	float dis = sqrt(pow(outlineSize*cos(rad),2.0)+ pow(outlineSize*sin(rad),2.0) );  
	
	if(a >= 0.5){
		stroke = dis;
		findNum++;
	}
	return stroke;
}


void main()
{
	///首先获得每个像素的颜色
	vec4 myC = texture2D(CC_Texture0 , v_texCoord);
	if(myC.a >= 0.5){
		gl_FragColor = v_fragmentColor*myC;
		return;
		
	}
	//else{
	//	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	//	return;
	//}
	
	float strokeCount = 0.0;  
    strokeCount += getIsStrokeWithAngel(0.0);  
    strokeCount += getIsStrokeWithAngel(30.0);  
    strokeCount += getIsStrokeWithAngel(60.0);  
    strokeCount += getIsStrokeWithAngel(90.0);  
    strokeCount += getIsStrokeWithAngel(120.0);  
    strokeCount += getIsStrokeWithAngel(150.0);  
    strokeCount += getIsStrokeWithAngel(180.0);  
    strokeCount += getIsStrokeWithAngel(210.0);  
    strokeCount += getIsStrokeWithAngel(240.0);  
    strokeCount += getIsStrokeWithAngel(270.0);  
    strokeCount += getIsStrokeWithAngel(300.0);  
    strokeCount += getIsStrokeWithAngel(330.0);  
  
    if (strokeCount > 0.0) // 四周围至少有一个点是不透明的，这个点要设成描边颜色  
    {  
        myC = vec4(outlineColor, 1) ;  
    }  
  
    gl_FragColor = v_fragmentColor * myC;  
}