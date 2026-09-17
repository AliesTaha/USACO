class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height)-1
        maxi=0

        while l<r:
            hl, hr=height[l], height[r]
            dist=r-l
            curr=dist*min(hl, hr)
            maxi=max(maxi, curr)
            if hl<hr:
                l+=1
            else:
                r-=1
        
        return maxi
        