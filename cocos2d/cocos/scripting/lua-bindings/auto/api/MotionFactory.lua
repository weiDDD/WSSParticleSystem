
--------------------------------
-- @module MotionFactory
-- @extend Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#MotionFactory] getProperty 
-- @param self
-- @param #string propName
-- @return Value#Value ret (return value: cc.Value)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] prepareMotionCreator 
-- @param self
-- @return MotionFactory#MotionFactory self (return value: cc.MotionFactory)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] setName 
-- @param self
-- @param #char name
-- @return MotionFactory#MotionFactory self (return value: cc.MotionFactory)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] createMotion 
-- @param self
-- @param #cc.MotionContext context
-- @return Motion#Motion ret (return value: cc.Motion)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] getName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] loadPropertiesFromXmlAccessor 
-- @param self
-- @param #cc.TinyxmlAccessor accessor
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#MotionFactory] getProperties 
-- @param self
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- @overload self, string         
-- @overload self         
-- @overload self, string, array_table         
-- @function [parent=#MotionFactory] create
-- @param self
-- @param #string name
-- @param #array_table children
-- @return MotionFactory#MotionFactory ret (return value: cc.MotionFactory)

return nil
