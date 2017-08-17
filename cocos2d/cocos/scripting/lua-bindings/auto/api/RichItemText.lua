
--------------------------------
-- @module RichItemText
-- @extend RichItem
-- @parent_module ccui

--------------------------------
-- 
-- @function [parent=#RichItemText] init 
-- @param self
-- @param #int tag
-- @param #color3b_table color
-- @param #unsigned char opacity
-- @param #char text
-- @param #char fontName
-- @param #float fontSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#RichItemText] enableOutLine 
-- @param self
-- @param #color4b_table outcolor
-- @param #unsigned char outlinesize
-- @return RichItemText#RichItemText self (return value: ccui.RichItemText)
        
--------------------------------
-- 
-- @function [parent=#RichItemText] enableLinkLine 
-- @param self
-- @param #color4b_table linkcolor
-- @param #unsigned char linksize
-- @return RichItemText#RichItemText self (return value: ccui.RichItemText)
        
--------------------------------
-- 
-- @function [parent=#RichItemText] create 
-- @param self
-- @param #int tag
-- @param #color3b_table color
-- @param #unsigned char opacity
-- @param #char text
-- @param #char fontName
-- @param #float fontSize
-- @return RichItemText#RichItemText ret (return value: ccui.RichItemText)
        
--------------------------------
-- 
-- @function [parent=#RichItemText] lookupObject 
-- @param self
-- @param #unsigned int id
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#RichItemText] RichItemText 
-- @param self
-- @return RichItemText#RichItemText self (return value: ccui.RichItemText)
        
return nil
