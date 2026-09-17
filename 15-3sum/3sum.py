class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums)==3:
            if sum(nums)==0:
                return [nums]
        
        nums=sorted(nums)
        ret=set()

        for a, num in enumerate(nums):
            if a>0 and nums[a]==nums[a-1]:
                continue
            b=a+1
            c=len(nums)-1
            while b<c:
                num1=nums[a]
                num2=nums[b]
                num3=nums[c]
                the_sum=num1+num2+num3

                if the_sum==0:
                    ret.add((num1, num2, num3))
                    if b+1!=c: #reset piano
                        c-=1
                        continue

                if b+1==c: 
                    break
                        
                if the_sum>0:
                    c-=1
                elif the_sum<0:
                    b+=1
        
        return list(ret) #game over