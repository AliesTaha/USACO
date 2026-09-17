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
        curr_sum=0
        ret=set()

        for a in range(len(nums)):
            b=a+1
            c=len(nums)-1
            while b<c:
                num1=nums[a]
                num2=nums[b]
                num3=nums[c]
                the_sum=num1+num2+num3

                if the_sum==0:
                    ret.add((num1, num2, num3))
                    #special case need to do something if = 0
                    #can move anything, choose to move the right
                    if b+1!=c: #reset piano
                        c-=1
                        continue

                if b+1==c: 
                    if a+1==b:
                        return list(ret) #game over
                    else:
                        break #reset piano
                        
                if the_sum>0:
                    c-=1
                    continue
            
                if the_sum<0:
                    b+=1
                    continue
        
