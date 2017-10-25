
--------------------------------
-- @module ParticleEmitter
-- @extend Node
-- @parent_module pp

--------------------------------
-- 
-- @function [parent=#ParticleEmitter] getFirstFirePro 
-- @param self
-- @return emitterFirePro#emitterFirePro ret (return value: emitterFirePro)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] readJsonDataFromFile 
-- @param self
-- @param #string filename
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] getIsActive 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_varietyValue_pushCurveValue 
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float x
-- @param #float value
-- @param #float randValue
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_duration 
-- @param self
-- @param #int id
-- @param #float duration
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] getChildrenParById 
-- @param self
-- @param #int id
-- @return childrenPar#childrenPar ret (return value: childrenPar)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_fireArea_pushPolygonPoint 
-- @param self
-- @param #int id
-- @param #float posX
-- @param #float posY
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_MaxParticleNum 
-- @param self
-- @param #int id
-- @param #int num
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] stopSystem 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] createEmitter 
-- @param self
-- @return ParticleEmitter#ParticleEmitter ret (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_isLoop 
-- @param self
-- @param #int id
-- @param #bool loop
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_emissionRate 
-- @param self
-- @param #int id
-- @param #float rate
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] removeFireProById 
-- @param self
-- @param #int id
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] clearData 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- @overload self, int, string, float, float, float, float, float, float         
-- @overload self, int, string, float, float, float         
-- @function [parent=#ParticleEmitter] setFirePro_colorValue
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float randcolor1_r
-- @param #float randcolor1_g
-- @param #float randcolor1_b
-- @param #float randcolor2_r
-- @param #float randcolor2_g
-- @param #float randcolor2_b
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)

--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_fireArea_clear 
-- @param self
-- @param #int id
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_ParType 
-- @param self
-- @param #int id
-- @param #string type
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] visit 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table parentTransform
-- @param #unsigned int parentFlags
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setChildrenParNewId 
-- @param self
-- @param #int oldid
-- @param #int newid
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_EmitterFileName 
-- @param self
-- @param #int id
-- @param #string name
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setIsAutoRemoveOnFinish 
-- @param self
-- @param #bool autoRemove
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_FireAngleType 
-- @param self
-- @param #int id
-- @param #string type
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] getFireProById 
-- @param self
-- @param #int id
-- @return emitterFirePro#emitterFirePro ret (return value: emitterFirePro)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_DestBlend 
-- @param self
-- @param #int id
-- @param #int destBlend
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] releaseRender 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_delayTime 
-- @param self
-- @param #int id
-- @param #float delay
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_tailPro 
-- @param self
-- @param #int id
-- @param #string tailName
-- @param #float fade
-- @param #float minSeg
-- @param #float stroke
-- @param #float color_r
-- @param #float color_g
-- @param #float color_b
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] writeJsonData 
-- @param self
-- @param #m_rapidjson.GenericDocument<m_rapidjson.UTF8<char>, m_rapidjson.MemoryPoolAllocator<m_rapidjson.CrtAllocator> > object
-- @param #m_rapidjson.MemoryPoolAllocator<m_rapidjson.CrtAllocator> allocator
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_TexName 
-- @param self
-- @param #int id
-- @param #string texName
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] addOneFirePro 
-- @param self
-- @param #int id
-- @param #int type
-- @param #string fileName
-- @return emitterFirePro#emitterFirePro ret (return value: emitterFirePro)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] getVarietyValueByType 
-- @param self
-- @param #emitterFirePro firePro
-- @param #string type
-- @return emitterVarietyValue#emitterVarietyValue ret (return value: emitterVarietyValue)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_colorValue_clear 
-- @param self
-- @param #int id
-- @param #string valueType
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_colorValue_pushCurveValue 
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float x
-- @param #float color_r
-- @param #float color_g
-- @param #float color_b
-- @param #float randcolor_r
-- @param #float randcolor_g
-- @param #float randcolor_b
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] update 
-- @param self
-- @param #float dt
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] readJsonData 
-- @param self
-- @param #m_rapidjson.GenericDocument<m_rapidjson.UTF8<char>, m_rapidjson.MemoryPoolAllocator<m_rapidjson.CrtAllocator> > doc
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirepro_varietyValue_pushMoreValue 
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float value
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] resetSystem 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- @overload self, int, float, float         
-- @overload self, int, float, float, float, float         
-- @function [parent=#ParticleEmitter] setFirePro_fireArea
-- @param self
-- @param #int id
-- @param #float inRectWidth
-- @param #float inRectHeight
-- @param #float outRectWidth
-- @param #float outRectHeight
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)

--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setRunningLayer 
-- @param self
-- @param #cc.Node layer
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- / ----------------------------------------------------- 提供给外部的修改 firePro 的函数-----------------------------------------------------------------------
-- @function [parent=#ParticleEmitter] setFirePro_LocalZOrder 
-- @param self
-- @param #int id
-- @param #int localZOrder
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_IsFlowCircleRadius 
-- @param self
-- @param #int id
-- @param #bool isFlow
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] addRender 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- @overload self, int, string, float, float         
-- @overload self, int, string, float         
-- @function [parent=#ParticleEmitter] setFirePro_varietyValue
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float randvalue1
-- @param #float randvalue2
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)

--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_fireArea_pushLinePoint 
-- @param self
-- @param #int id
-- @param #float posX
-- @param #float posY
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] clearRender 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_SourceBlend 
-- @param self
-- @param #int id
-- @param #int sourceBlend
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_varietyValue_clear 
-- @param self
-- @param #int id
-- @param #string valueType
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_AnchorPoint 
-- @param self
-- @param #int id
-- @param #float x
-- @param #float y
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_isLockRotationToMoveAngle 
-- @param self
-- @param #int id
-- @param #bool isLock
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirepro_colorValue_pushMoreValue 
-- @param self
-- @param #int id
-- @param #string valueType
-- @param #float color_r
-- @param #float color_g
-- @param #float color_b
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] refreshZorder 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_tailPro_isActive 
-- @param self
-- @param #int id
-- @param #bool isActive
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_preFireDuration 
-- @param self
-- @param #int id
-- @param #float preFire
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setFirePro_PositionType 
-- @param self
-- @param #int id
-- @param #string type
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setTestData 
-- @param self
-- @param #emitterFirePro pro
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#ParticleEmitter] create
-- @param self
-- @param #bool isInstance
-- @return ParticleEmitter#ParticleEmitter ret (return value: pp.ParticleEmitter)

--------------------------------
-- 
-- @function [parent=#ParticleEmitter] setSourcePath 
-- @param self
-- @param #string path
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] onEnter 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] onExit 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
--------------------------------
-- 
-- @function [parent=#ParticleEmitter] ParticleEmitter 
-- @param self
-- @return ParticleEmitter#ParticleEmitter self (return value: pp.ParticleEmitter)
        
return nil
