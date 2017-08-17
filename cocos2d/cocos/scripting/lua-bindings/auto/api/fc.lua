
--------------------------------
-- @module fc
-- @extend Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#fc] ValueMapFormat 
-- @param self
-- @param #map_table vm
-- @param #char format
-- @param #char delimiter
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#fc] ProfilingEndTimingBlock 
-- @param self
-- @param #char timerName
-- @return fc#fc self (return value: cc.fc)
        
--------------------------------
-- 
-- @function [parent=#fc] pathUnicode2utf8 
-- @param self
-- @param #string path
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#fc] pathUtf82unicode 
-- @param self
-- @param #string path
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#fc] getGlobalTime 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#fc] ProfilingBeginTimingBlock 
-- @param self
-- @param #char timerName
-- @return fc#fc self (return value: cc.fc)
        
--------------------------------
-- 
-- @function [parent=#fc] ProfilingDisplayTimers 
-- @param self
-- @return fc#fc self (return value: cc.fc)
        
--------------------------------
-- 
-- @function [parent=#fc] dockNodeInDevice 
-- @param self
-- @param #cc.Node node
-- @param #unsigned int dockType
-- @param #bool once
-- @return fc#fc self (return value: cc.fc)
        
--------------------------------
-- 
-- @function [parent=#fc] ProfilingResetTimingBlock 
-- @param self
-- @param #char timerName
-- @return fc#fc self (return value: cc.fc)
        
return nil
