class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dic=Counter(nums)
        
        def sort_key(x):
            return x[1]

        sorted_dic=sorted(
            dic.items(), 
            key = sort_key,
            reverse=True)
        ret=[]
        for i in range(k):
            k,v=sorted_dic[i]
            ret.append(k)
        return ret