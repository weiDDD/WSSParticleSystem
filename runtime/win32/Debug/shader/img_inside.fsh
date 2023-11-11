///fsh为碎片shader,纹理的每个像素都会应用此shader,每个像素都会调用

///接收从vsh中传入的数据:顶点颜色
varying vec4 v_fragmentColor;
///接收从vsh中传入的数据:纹理坐标, 每一个像素执行时，会根据差值求出每个像素的具体纹理坐标
varying vec2 v_texCoord;

varying vec4 v_pos;

///C程序中传入的纹理数据
uniform sampler2D Texture;

void main()
{
	///首先获得每个像素的颜色
	gl_FragColor = texture2D(Texture , v_texCoord) * v_fragmentColor;
	
	vec4 color2 = texture2D(CC_Texture1 , vec2((v_pos.x) / 64.0 + 0.5, 0.5 - (v_pos.y) / 64.0) );
	
	
	//if(v_pos.x > 200.0 || v_pos.x < 100.0 || v_pos.y > 200.0 || v_pos.y < 100.0){
	//	gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
	//}
	
	//if(distance(vec2(v_pos.x, v_pos.y), vec2(0.0, 0.0)) > 100.0 ){
	//	gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
	//}
	
	if(color2.a <= 0.1){
		gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
	}
}