
--------------------------------
-- @module ObjectPool
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#ObjectPool] reset 
-- @param self
-- @return ObjectPool#ObjectPool self (return value: cc.ObjectPool)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] resetByName 
-- @param self
-- @param #char poolName
-- @return ObjectPool#ObjectPool self (return value: cc.ObjectPool)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] pushObject 
-- @param self
-- @param #char poolName
-- @param #cc.Ref object
-- @return ObjectPool#ObjectPool self (return value: cc.ObjectPool)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] popObject 
-- @param self
-- @param #char poolName
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] destroyObject 
-- @param self
-- @return ObjectPool#ObjectPool self (return value: cc.ObjectPool)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] getInstance 
-- @param self
-- @return ObjectPool#ObjectPool ret (return value: cc.ObjectPool)
        
--------------------------------
-- 
-- @function [parent=#ObjectPool] ObjectPool 
-- @param self
-- @return ObjectPool#ObjectPool self (return value: cc.ObjectPool)
        
return nil
