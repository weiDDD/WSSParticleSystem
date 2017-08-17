
--------------------------------
-- @module ZipUtils
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#ZipUtils] setPvrEncryptionKey 
-- @param self
-- @param #unsigned int keyPart1
-- @param #unsigned int keyPart2
-- @param #unsigned int keyPart3
-- @param #unsigned int keyPart4
-- @return ZipUtils#ZipUtils self (return value: cc.ZipUtils)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] inflateMemory 
-- @param self
-- @param #unsigned char in
-- @param #long inLength
-- @param #unsigned char out
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] isCCZFile 
-- @param self
-- @param #char filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] setPvrEncryptionKeyPart 
-- @param self
-- @param #int index
-- @param #unsigned int value
-- @return ZipUtils#ZipUtils self (return value: cc.ZipUtils)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] isCCZBuffer 
-- @param self
-- @param #unsigned char buffer
-- @param #long len
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] isGZipFile 
-- @param self
-- @param #char filename
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] inflateMemoryWithHint 
-- @param self
-- @param #unsigned char in
-- @param #long inLength
-- @param #unsigned char out
-- @param #long outLengthHint
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] inflateCCZBuffer 
-- @param self
-- @param #unsigned char buffer
-- @param #long len
-- @param #unsigned char out
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] inflateGZipFile 
-- @param self
-- @param #char filename
-- @param #unsigned char out
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] isGZipBuffer 
-- @param self
-- @param #unsigned char buffer
-- @param #long len
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ZipUtils] inflateCCZFile 
-- @param self
-- @param #char filename
-- @param #unsigned char out
-- @return int#int ret (return value: int)
        
return nil
