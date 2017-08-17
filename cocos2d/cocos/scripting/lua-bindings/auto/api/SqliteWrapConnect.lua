
--------------------------------
-- @module SqliteWrapConnect
-- @extend Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] begin 
-- @param self
-- @return SqliteWrapConnect#SqliteWrapConnect self (return value: cc.SqliteWrapConnect)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] tableExists 
-- @param self
-- @param #char tableName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] initWithDbFile 
-- @param self
-- @param #string dbFile
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, char, map_table         
-- @overload self, char         
-- @function [parent=#SqliteWrapConnect] exec
-- @param self
-- @param #char sql
-- @param #map_table fmtValues
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] lastInsertRowid 
-- @param self
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- @overload self, char, map_table         
-- @overload self, char         
-- @function [parent=#SqliteWrapConnect] isRowExist
-- @param self
-- @param #char sql
-- @param #map_table fmtValues
-- @return bool#bool ret (return value: bool)

--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] insertRow 
-- @param self
-- @param #char tableName
-- @param #map_table row
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, char, map_table         
-- @overload self, char         
-- @function [parent=#SqliteWrapConnect] query
-- @param self
-- @param #char sql
-- @param #map_table fmtValues
-- @return SqliteWrapQuery#SqliteWrapQuery ret (return value: cc.SqliteWrapQuery)

--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] commit 
-- @param self
-- @return SqliteWrapConnect#SqliteWrapConnect self (return value: cc.SqliteWrapConnect)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] close 
-- @param self
-- @return SqliteWrapConnect#SqliteWrapConnect self (return value: cc.SqliteWrapConnect)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] writeKeyValues 
-- @param self
-- @param #char table
-- @param #char keyFieldName
-- @param #char valueFieldName
-- @param #map_table keyMap
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, map_table, char         
-- @overload self, char         
-- @function [parent=#SqliteWrapConnect] querySingleValue
-- @param self
-- @param #map_table fmtValues
-- @param #char sql
-- @return Value#Value ret (return value: cc.Value)

--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] updateRow 
-- @param self
-- @param #char tableName
-- @param #map_table row
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] getDb 
-- @param self
-- @return sqlite3#sqlite3 ret (return value: sqlite3)
        
--------------------------------
-- 
-- @function [parent=#SqliteWrapConnect] create 
-- @param self
-- @return SqliteWrapConnect#SqliteWrapConnect ret (return value: cc.SqliteWrapConnect)
        
return nil
