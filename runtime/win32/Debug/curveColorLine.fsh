///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用
#ifdef GL_ES
precision hight float;
#endif

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标
///每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;
///C程序中传入的纹理数据
uniform sampler2D Texture;

const int colorMaxNum = 30;
uniform float pos[colorMaxNum];
uniform float colorR[colorMaxNum];
uniform float colorG[colorMaxNum];
uniform float colorB[colorMaxNum];

uniform int colorNum;

void main()
{
	///首先获得每个像素的颜色
	vec4 v_orColor = v_fragmentColor * texture2D(Texture , v_texCoord);
	vec3 nowColor = vec3(255,255,0);
	
	for(int i=0;i<colorNum-1;++i){
		float leftPos = pos[i];
		float rightPos = pos[i+1];
		if(v_texCoord.x >= leftPos && v_texCoord.x < rightPos){
			vec3 leftColor = vec3(colorR[i] , colorG[i] , colorB[i]);
			vec3 rightColor = vec3(colorR[i+1] , colorG[i+1] , colorB[i+1]);
			
			float precent = (v_texCoord.x - leftPos) / (rightPos - leftPos);
			nowColor = vec3( leftColor.x + precent * (rightColor.x - leftColor.x),
							leftColor.y + precent * (rightColor.y - leftColor.y),
								leftColor.z + precent * (rightColor.z - leftColor.z) );
								
			
		}
		
	}
	
	gl_FragColor = vec4(nowColor.x / 255.0 , nowColor.y / 255.0 , nowColor.z / 255.0 ,v_orColor.a);
	
}