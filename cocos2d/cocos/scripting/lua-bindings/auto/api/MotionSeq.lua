
--------------------------------
-- @module MotionSeq
-- @extend Motion
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#MotionSeq] onPopFromPool 
-- @param self
-- @return MotionSeq#MotionSeq self (return value: cc.MotionSeq)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] onPushToPool 
-- @param self
-- @return MotionSeq#MotionSeq self (return value: cc.MotionSeq)
        
--------------------------------
-- @overload self, array_table         
-- @overload self         
-- @function [parent=#MotionSeq] create
-- @param self
-- @param #array_table childs
-- @return MotionSeq#MotionSeq ret (return value: cc.MotionSeq)

--------------------------------
-- 
-- @function [parent=#MotionSeq] resetPool 
-- @param self
-- @return MotionSeq#MotionSeq self (return value: cc.MotionSeq)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] poolName 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] getPoolName 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] start 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] stop 
-- @param self
-- @return MotionSeq#MotionSeq self (return value: cc.MotionSeq)
        
--------------------------------
-- 
-- @function [parent=#MotionSeq] update 
-- @param self
-- @param #float delta
-- @return MotionSeq#MotionSeq self (return value: cc.MotionSeq)
        
return nil
