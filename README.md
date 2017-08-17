WSSParticleSystem
一个基于cocos2dx开发的粒子系统  
  
•是什么:  
      1.一套 源自cocos2dx 服务cocos2dx 的粒子系统代码.  
      2.一款 粒子系统编辑器.  
      
•怎么玩:  
      1.源码  位于 Classes 文件夹下.  
      2.编辑器程序  位于 runtime/win32/debug下.   
      3.粒子系统所用纹理  位于 runtime/win32/debug/texture下.   
      4.导出粒子文件  位于 runtime/win32/debug/json下.   
      5.编辑器中的参考图  位于  runtime/win32/debug/refSprite文件夹下.   
      6.拖尾纹理  位于 runtime/win32/debug/tail文件夹下.   
      
•应用到自己项目:   
      1.添加源码到自己的工程中编译:   
          将Classes中的FileCenter ; lua_particle_system_auto ; ParticleEmitter ; ParticleRenderer ; UpdateHelper 的h,cpp文件拷到自己的工程中。   
          
      2.注册C++到lua:(如果是lua工程)   
          在合适的地方(一般是工程开始的地方，如 appDelegate 文件的 applicationDidFinishLaunching 函数中)，调用 lua_particle_system_auto.cpp 中的register_all_particle_system 函数将C++绑定到lua.   
          
      3.代码使用:   
        C++:   
            
	  auto par = ParticleEmitter::create();   
	  par->readJsonDataFromFile("json/test1.par");   
	  par->setPosition(Vec2(800, 500));   
	  this->addChild(par);   
               
        lua:     
              
         local par = pp.ParticleEmitter:create()   
         par:setPosition( cc.p(500,500) )   
         par:readJsonDataFromFile("res/image/test1.par");   
         self:addChild(par)   
         
•PS:   
      1.本人联系方式:QQ:1139454623  有什么bug或建议可以给我说.   
      2.如果你觉得本项目还可以请点赞哟(随手点赞好习惯哦！)   
      3.如果本项目对你有所帮助,希望可以打赏一点零花钱哦 ^-^ (支付宝账号:1139454623@qq.com)   
         
         
         
•Licensing:   
  This software is licensed under the terms you may find in the file named "LICENSE" in this directory.   

This distribution includes cryptographic software. The country in which you currently reside may have restrictions on the import, possession, use, and/or re-export to another country, of encryption software. BEFORE using any encryption software, please check your country's laws, regulations and policies concerning the import, possession, or use, and re-export of encryption software, to see if this is permitted. See http://www.wassenaar.org/ for more information.   
   
The U.S. Government Department of Commerce, Bureau of Industry and Security (BIS), has classified this software as Export Commodity Control Number (ECCN) 5D002.C.1, which includes information security software using or performing cryptographic functions with asymmetric algorithms. The form and manner of this Apache Software Foundation distribution makes it eligible for export under the License Exception ENC Technology Software Unrestricted (TSU) exception (see the BIS Export Administration Regulations, Section 740.13) for both object code and source code.   
   
The following provides more details on the included cryptographic software:   
   
ActiveMQ supports the use of SSL TCP connections when used with with a JVM supporting the Java Cryptography extensions http://www.oracle.com/technetwork/java/javase/tech/index-jsp-136007.html. ActiveMQ does not include these libraries itself, but is designed to use them.   
      
