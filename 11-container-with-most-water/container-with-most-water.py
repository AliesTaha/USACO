class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        max_water=0
        while l<r:
            hr, hl=height[r], height[l]
            width=r-l
            water=width * min(hr, hl)
            max_water=max(water, max_water)
            if hr>hl:
                l+=1
            else:
                r-=1
        
        return max_water