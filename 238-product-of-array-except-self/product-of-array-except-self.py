class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l_arr=[1]*len(nums)
        r_arr=[1]*len(nums)

        for i in range(len(nums)):
            if i==0:
                l_arr[i]=nums[i]
            else:
                l_arr[i]=l_arr[i-1]*nums[i]

        for k in range(len(nums)-1, -1, -1):
            if k==len(nums)-1:
                r_arr[k]=nums[k]
            else:
                r_arr[k]=r_arr[k+1]*nums[k]
        
        ret=[0]*len(nums)
        for i in range(len(nums)):
            if i==0:
                ret[i]=r_arr[i+1]
            elif i==len(nums)-1:
                ret[i]=l_arr[i-1]
            else:
                ret[i]=l_arr[i-1]*r_arr[i+1]
        
        return ret