
--------------------------------
-- @module Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#Ref] setLuaDerivedRefId 
-- @param self
-- @param #int refId
-- @return Ref#Ref self (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#Ref] decAutorelease 
-- @param self
-- @return Ref#Ref self (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#Ref] getPoolName 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#Ref] getAutoReleaseCount 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#Ref] isObjectLiving 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- Returns the Ref's current reference count.<br>
-- returns The Ref's reference count.<br>
-- js NA
-- @function [parent=#Ref] getReferenceCount 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- Releases the ownership immediately.<br>
-- This decrements the Ref's reference count.<br>
-- If the reference count reaches 0 after the descrement, this Ref is<br>
-- destructed.<br>
-- see retain, autorelease<br>
-- js NA
-- @function [parent=#Ref] release 
-- @param self
-- @return Ref#Ref self (return value: cc.Ref)
        
--------------------------------
-- Retains the ownership.<br>
-- This increases the Ref's reference count.<br>
-- see release, autorelease<br>
-- js NA
-- @function [parent=#Ref] retain 
-- @param self
-- @return Ref#Ref self (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#Ref] incAutorelease 
-- @param self
-- @return Ref#Ref self (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#Ref] getRealRefrenceCount 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#Ref] getTotalObjectCount 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
return nil
