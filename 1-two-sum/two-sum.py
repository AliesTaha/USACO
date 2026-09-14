class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic={}
        for i,num in enumerate(nums):
            indices=[]
            if num in dic:
                indices=dic[num]
            indices.append(i)
            dic[num]=indices

        for num in nums:
            other=target-num
            if other in dic.keys():
                if num!=other:
                    return [dic[num][0],dic[other][0]]
                else:
                    if len(dic[other])>1:
                        return [dic[num][0],dic[num][1]]
                