class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        #array nums increasing, max of number of pos and neg ints
        pos, neg=0,0
        for num in nums:
            if num>0:
                pos+=1
            if num<0:
                neg+=1
        return max(pos, neg)