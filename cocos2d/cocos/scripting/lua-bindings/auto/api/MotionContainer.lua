
--------------------------------
-- @module MotionContainer
-- @extend Ref
-- @parent_module cc

--------------------------------
-- 
-- @function [parent=#MotionContainer] stopMotion 
-- @param self
-- @param #int id
-- @return MotionContainer#MotionContainer self (return value: cc.MotionContainer)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] findMotionFromKey 
-- @param self
-- @param #int id
-- @param #char key
-- @return Motion#Motion ret (return value: cc.Motion)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] update 
-- @param self
-- @param #float dt
-- @return MotionContainer#MotionContainer self (return value: cc.MotionContainer)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] runMotion 
-- @param self
-- @param #cc.Motion motion
-- @param #cc.MotionContext context
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] findMotion 
-- @param self
-- @param #int id
-- @return Motion#Motion ret (return value: cc.Motion)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] findContext 
-- @param self
-- @param #int id
-- @return MotionContext#MotionContext ret (return value: cc.MotionContext)
        
--------------------------------
-- 
-- @function [parent=#MotionContainer] create 
-- @param self
-- @return MotionContainer#MotionContainer ret (return value: cc.MotionContainer)
        
return nil
