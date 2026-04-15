class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        global_set=[]
        def helper(i, currset):
            if i>=len(nums):
                global_set.append(currset)
                return
            global_num=nums[i]
            new_set=currset[::]
            new_set.append(global_num)
            helper(i+1, new_set)
            helper(i+1, currset)
        helper(0, [])
        return global_set