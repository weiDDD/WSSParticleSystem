
--------------------------------
-- @module GUIReader
-- @extend Ref
-- @parent_module ccs

--------------------------------
-- 
-- @function [parent=#GUIReader] setFilePath 
-- @param self
-- @param #string strFilePath
-- @return GUIReader#GUIReader self (return value: ccs.GUIReader)
        
--------------------------------
-- js NA
-- @function [parent=#GUIReader] getFileDesignSize 
-- @param self
-- @param #char fileName
-- @return size_table#size_table ret (return value: size_table)
        
--------------------------------
-- js NA
-- @function [parent=#GUIReader] storeFileDesignSize 
-- @param self
-- @param #char fileName
-- @param #size_table size
-- @return GUIReader#GUIReader self (return value: ccs.GUIReader)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] widgetFromJsonFile 
-- @param self
-- @param #char fileName
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] getFilePath 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] widgetFromBinaryFile 
-- @param self
-- @param #char fileName
-- @return Widget#Widget ret (return value: ccui.Widget)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] getJsonCacheDocument 
-- @param self
-- @param #string file
-- @return GenericDocument<UTF8<char>, MemoryPoolAllocator<CrtAllocator> >#GenericDocument<UTF8<char>, MemoryPoolAllocator<CrtAllocator> > ret (return value: rj.GenericDocument<rj.UTF8<char>, rj.MemoryPoolAllocator<rj.CrtAllocator> >)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] getVersionInteger 
-- @param self
-- @param #char str
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] destroyInstance 
-- @param self
-- @return GUIReader#GUIReader self (return value: ccs.GUIReader)
        
--------------------------------
-- 
-- @function [parent=#GUIReader] getInstance 
-- @param self
-- @return GUIReader#GUIReader ret (return value: ccs.GUIReader)
        
return nil
