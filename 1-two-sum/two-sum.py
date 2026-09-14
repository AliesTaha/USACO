class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_prev={}

        for i, num in enumerate(nums):
            want=target-num
            if want in seen_prev:
                return [seen_prev[want], i]
            seen_prev[num]=i