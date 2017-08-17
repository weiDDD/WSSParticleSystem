
--------------------------------
-- @module RichTextUI
-- @extend ScrollView,LableDelegate
-- @parent_module ccui

--------------------------------
-- 
-- @function [parent=#RichTextUI] insertElement 
-- @param self
-- @param #ccui.RichItem element
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] setLineSpace 
-- @param self
-- @param #short lineSpace
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] setAnchorPoint 
-- @param self
-- @param #vec2_table pt
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] insertNewLine 
-- @param self
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] getHAlignment 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] setTextAlignment 
-- @param self
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] parseElement 
-- @param self
-- @param #char format
-- @param #bool clear
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] createTyping 
-- @param self
-- @return RichTextTyping#RichTextTyping ret (return value: ccui.RichTextTyping)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] getVAlignment 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] showItemByTag 
-- @param self
-- @param #short tag
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] getText 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] setMaxLine 
-- @param self
-- @param #short lineCount
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] labelClicked 
-- @param self
-- @param #ccui.LinkLable lab
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] clearAll 
-- @param self
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] isEnglishChar 
-- @param self
-- @param #char c
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] create 
-- @param self
-- @return RichTextUI#RichTextUI ret (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] lookupObject 
-- @param self
-- @param #unsigned int id
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] setOpacity 
-- @param self
-- @param #unsigned char opacity
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] updateDisplayedOpacity 
-- @param self
-- @param #unsigned char parentOpacity
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
--------------------------------
-- 
-- @function [parent=#RichTextUI] RichTextUI 
-- @param self
-- @return RichTextUI#RichTextUI self (return value: ccui.RichTextUI)
        
return nil
