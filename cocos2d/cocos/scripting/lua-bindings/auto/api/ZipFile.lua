
--------------------------------
-- @module ZipFile
-- @parent_module cc

--------------------------------
-- Check does a file exists or not in zip file<br>
-- param fileName File to be checked on existance<br>
-- return true whenever file exists, false otherwise<br>
-- since v2.0.5
-- @function [parent=#ZipFile] fileExists 
-- @param self
-- @param #string fileName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZipFile] getFirstFilename 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZipFile] writeFileData 
-- @param self
-- @param #string fileName
-- @param #string dir
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ZipFile] getNextFilename 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ZipFile] update 
-- @param self
-- @param #float dt
-- @return ZipFile#ZipFile self (return value: cc.ZipFile)
        
--------------------------------
-- 
-- @function [parent=#ZipFile] destroy 
-- @param self
-- @return ZipFile#ZipFile self (return value: cc.ZipFile)
        
--------------------------------
-- Regenerate accessible file list based on a new filter string.<br>
-- param filter New filter string (first part of files names)<br>
-- return true whenever zip file is open successfully and it is possible to locate<br>
-- at least the first file, false otherwise<br>
-- since v2.0.5
-- @function [parent=#ZipFile] setFilter 
-- @param self
-- @param #string filter
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, string, string         
-- @overload self, string         
-- @function [parent=#ZipFile] create
-- @param self
-- @param #string zipFile
-- @param #string filter
-- @return ZipFile#ZipFile ret (return value: cc.ZipFile)

return nil
