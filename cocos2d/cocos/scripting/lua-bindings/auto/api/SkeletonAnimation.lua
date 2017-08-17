
--------------------------------
-- @module SkeletonAnimation
-- @extend SkeletonRenderer
-- @parent_module sp

--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setTrackCompleteListener 
-- @param self
-- @param #spTrackEntry entry
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] findAnimation 
-- @param self
-- @param #string name
-- @return spAnimation#spAnimation ret (return value: spAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setTrackEventListener 
-- @param self
-- @param #spTrackEntry entry
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setMix 
-- @param self
-- @param #string fromAnimation
-- @param #string toAnimation
-- @param #float duration
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- /½«Ò»¸ö½Úµã¼Óµ½Ò»¸öslotÉÏ,,¿ÉÄÜ²»ÄÜÓÃÅ¶
-- @function [parent=#SkeletonAnimation] addNodeToBone 
-- @param self
-- @param #string slotName
-- @param #cc.Node childNode
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setTrackStartListener 
-- @param self
-- @param #spTrackEntry entry
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setEndListener 
-- @param self
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setCompleteListener 
-- @param self
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- »ñµÃÒ»¸ö¹ÇÍ·µÄÊÀ½çÎ»ÖÃ
-- @function [parent=#SkeletonAnimation] getBonePos 
-- @param self
-- @param #string boneName
-- @return vec2_table#vec2_table ret (return value: vec2_table)
        
--------------------------------
-- ÉèÖÃÒ»¸öspine¹Ç÷ÀÖÐµÄÒ»¸ö¹ÇÍ·µÄÆ¤·ô
-- @function [parent=#SkeletonAnimation] setOneBoneSkin 
-- @param self
-- @param #string boneName
-- @param #string skinName
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setEventListener 
-- @param self
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- /add by wss
-- @function [parent=#SkeletonAnimation] setDebugSlot 
-- @param self
-- @param #bool b
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] clearTrack 
-- @param self
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setSProgram 
-- @param self
-- @param #string vshName
-- @param #string fshName
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- /ÉèÖÃÒ»¸ö¹ÇÍ·µÄÐý×ª
-- @function [parent=#SkeletonAnimation] setBoneRotation 
-- @param self
-- @param #char boneName
-- @param #float r
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] getAnimationTime 
-- @param self
-- @param #string name
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] clearTracks 
-- @param self
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setTrackEndListener 
-- @param self
-- @param #spTrackEntry entry
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setDebugBone 
-- @param self
-- @param #bool b
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] setStartListener 
-- @param self
-- @param #function listener
-- @return SkeletonAnimation#SkeletonAnimation self (return value: sp.SkeletonAnimation)
        
--------------------------------
-- /»ñµÃÒ»¸ö¹ÇÍ·µÄÐý×ª½Ç¶È
-- @function [parent=#SkeletonAnimation] getBoneAngle 
-- @param self
-- @param #string boneName
-- @return float#float ret (return value: float)
        
--------------------------------
-- @overload self, string, string, float         
-- @overload self, string, spAtlas, float         
-- @function [parent=#SkeletonAnimation] createWithBinaryFile
-- @param self
-- @param #string skeletonBinaryFile
-- @param #spAtlas atlas
-- @param #float scale
-- @return SkeletonAnimation#SkeletonAnimation ret (return value: sp.SkeletonAnimation)

--------------------------------
-- 
-- @function [parent=#SkeletonAnimation] create 
-- @param self
-- @return SkeletonAnimation#SkeletonAnimation ret (return value: sp.SkeletonAnimation)
        
--------------------------------
-- @overload self, string, string, float         
-- @overload self, string, spAtlas, float         
-- @function [parent=#SkeletonAnimation] createWithJsonFile
-- @param self
-- @param #string skeletonJsonFile
-- @param #spAtlas atlas
-- @param #float scale
-- @return SkeletonAnimation#SkeletonAnimation ret (return value: sp.SkeletonAnimation)

return nil
