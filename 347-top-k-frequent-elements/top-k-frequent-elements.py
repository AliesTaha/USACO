class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dic=Counter(nums)
        sorted_dic=sorted(
            dic.items(), 
            key = lambda x: x[1], 
            reverse=True)
        ret=[]
        for i in range(k):
            k,v=sorted_dic[i]
            ret.append(k)
        return ret