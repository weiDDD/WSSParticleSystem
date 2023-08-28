
precision highp float;  

varying vec4 v_color;

const float PI = 3.1415926535897932;  

const float speed = 0.2;  
const float speed_x = 0.3;  
const float speed_y = 0.3;  
 
const float intensity = 1;       //强度
const float frequency = 10.0;    //频率 

const int angle = 7; 
 
const float delta = 20.0;  
const float intence = 400.0;  
const float emboss = 0.022;
 
const float sampleNum = 10;

varying vec2 v_texCoord;
 
float col(vec2 coord)  
{  
	float time = CC_Time[1];
	// 一个圆角度切成 n 份
    float delta_theta = 2.0 * PI / float(angle);  
    float col = 0.0;
    float theta = 0.0;  
    for (int i = 0; i <= angle; i++)  
    {
		// 先拿到纹理坐标
        vec2 adjc = coord;
		// 当前要处理哪个角度
		theta = delta_theta * float(i);
		// 这个角度上，速度 * cos() 表示x上的移动距离； 速度*sin() 表示y上的移动距离
		adjc.x = adjc.x + cos(theta) * time * speed  + time * speed_x;  
		adjc.y = adjc.y - sin(theta) * time * speed  + time * speed_y; 
        
		// (adjc.x * cos(theta) - adjc.y * sin(theta)) -> 可以理解成 r * cos(n + theta) , r是原点到(x, y)的距离; 
        // r * cos(n + theta) 可以理解为这个(x, y) 在 theta 这个角度上的投影。
        col = col + cos((adjc.x * cos(theta) - adjc.y * sin(theta)) * frequency) * intensity;
    }
    return cos(col);
}  

void main(void)  
{  
	vec2 p = (v_texCoord.xy), c1 = p, c2 = p;  
    float cc1 = col(c1);  
	
    float offset = (2 * PI) / (frequency * sampleNum);

	// c2表示一个偏移的位置，然后算出c2的cos值跟 c1的差值。如果是平缓的地方差值越小，陡峭的地方差值越大。
    c2.x += offset;
    float dx = emboss*(cc1 - col(c2));
 
    c2.x = p.x;  
    c2.y += offset;
    float dy = emboss*(cc1 - col(c2));  
 
    c1.x += dx;
    c1.y += dy;
    float alpha = 1.0 + 2.0 * dx * dy * intence;  
    gl_FragColor = texture2D(CC_Texture0, c1) * alpha * v_color;
}