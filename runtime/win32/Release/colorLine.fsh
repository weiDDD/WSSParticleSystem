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

void main()
{
	///首先获得每个像素的颜色
	vec4 v_orColor = v_fragmentColor * texture2D(Texture , v_texCoord);
	
	vec3 startColor;
	vec3 endColor;
	float startY;
	float endY;
	
	if(v_texCoord.y <= 1.0/6.0){
		startColor = vec3(255,0,0);
		endColor = vec3(255,0,255);
		startY = 0.0;
		endY = 1.0/6.0;
	}
	else if(v_texCoord.y <= 2.0/6.0){
		startColor = vec3(255,0,255);
		endColor = vec3(0,0,255);
		startY = 1.0/6.0;
		endY = 2.0/6.0;
	}
	else if(v_texCoord.y <= 3.0/6.0){
		startColor = vec3(0,0,255);
		endColor = vec3(0,255,255);
		startY = 2.0/6.0;
		endY = 3.0/6.0;
	}
	else if(v_texCoord.y <= 4.0/6.0){
		startColor = vec3(0,255,255);
		endColor = vec3(0,255,0);
		startY = 3.0/6.0;
		endY = 4.0/6.0;
	}
	else if(v_texCoord.y <= 5.0/6.0){
		startColor = vec3(0,255,0);
		endColor = vec3(255,255,0);
		startY = 4.0/6.0;
		endY = 5.0/6.0;
	}
	else if(v_texCoord.y <= 6.0/6.0){
		startColor = vec3(255,255,0);
		endColor = vec3(255,0,0);
		startY = 5.0/6.0;
		endY = 6.0/6.0;
	}
	
	vec3 nowColor = vec3( startColor.x + (v_texCoord.y-startY) / (endY-startY) * (endColor.x - startColor.x ) ,
							startColor.y + (v_texCoord.y-startY) / (endY-startY) * (endColor.y - startColor.y ),
								startColor.z + (v_texCoord.y-startY) / (endY-startY) * (endColor.z - startColor.z ));
	
	gl_FragColor = vec4(nowColor.x / 255.0 , nowColor.y / 255.0 , nowColor.z / 255.0 ,v_orColor.a);
	
}