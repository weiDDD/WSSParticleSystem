
--------------------------------
-- @module RichItemImage
-- @extend RichItem
-- @parent_module ccui

--------------------------------
-- @overload self, int, color3b_table, unsigned char, cc.Sprite         
-- @overload self, int, color3b_table, unsigned char, char         
-- @overload self, int, color3b_table, unsigned char, ccui.ImageView         
-- @function [parent=#RichItemImage] init
-- @param self
-- @param #int tag
-- @param #color3b_table color
-- @param #unsigned char opacity
-- @param #ccui.ImageView sprite
-- @return bool#bool ret (return value: bool)

--------------------------------
-- @overload self, int, color3b_table, unsigned char, cc.Sprite         
-- @overload self, int, color3b_table, unsigned char, char         
-- @overload self, int, color3b_table, unsigned char, ccui.ImageView         
-- @function [parent=#RichItemImage] create
-- @param self
-- @param #int tag
-- @param #color3b_table color
-- @param #unsigned char opacity
-- @param #ccui.ImageView sprite
-- @return RichItemImage#RichItemImage ret (return value: ccui.RichItemImage)

--------------------------------
-- 
-- @function [parent=#RichItemImage] lookupObject 
-- @param self
-- @param #unsigned int id
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#RichItemImage] RichItemImage 
-- @param self
-- @return RichItemImage#RichItemImage self (return value: ccui.RichItemImage)
        
return nil
