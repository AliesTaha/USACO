class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height: return 0 

        l, r = 0, len(height)-1
        lm, rm= height[l], height[r]
        res=0

        while l<r:
            if lm<rm:
                l+=1
                lm=max(lm, height[l])
                res+=lm-height[l]
            else:
                r-=1
                rm=max(rm, height[r])
                res+=rm-height[r]

        return res


