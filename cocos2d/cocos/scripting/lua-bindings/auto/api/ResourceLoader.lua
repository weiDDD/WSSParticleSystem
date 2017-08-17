
--------------------------------
-- @module ResourceLoader
-- @extend Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#ResourceLoader] isMultiGroupLoaded 
-- @param self
-- @param #array_table groups
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] isGroupLoaded 
-- @param self
-- @param #string group
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] addGroup 
-- @param self
-- @param #string group
-- @param #array_table files
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getMultiGroupFileSize 
-- @param self
-- @param #array_table groups
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getGroupFileLoadedSize 
-- @param self
-- @param #string group
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getGroupLoadedPercent 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getMultiGroupFileLoadedSize 
-- @param self
-- @param #array_table groups
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getLoadingGroup 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getMultiGroupLoadedPercent 
-- @param self
-- @param #array_table groups
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getGroupFileSize 
-- @param self
-- @param #string group
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] destroyInstance 
-- @param self
-- @return ResourceLoader#ResourceLoader self (return value: cc.ResourceLoader)
        
--------------------------------
-- 
-- @function [parent=#ResourceLoader] getInstance 
-- @param self
-- @return ResourceLoader#ResourceLoader ret (return value: cc.ResourceLoader)
        
return nil
