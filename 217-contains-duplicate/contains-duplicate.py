class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        the_set=set(nums)
        return len(the_set)!=len(nums)