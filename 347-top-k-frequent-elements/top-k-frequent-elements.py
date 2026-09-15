class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        dic=Counter(nums)      
        
        arr=[[] for i in range(len(nums))]

        for key,v in dic.items():
            count=v-1
            arr[count].append(key)
        arr=arr[::-1]
        
        lis=[]
        count=0

        for group in arr:
            if count==k:
                break
            for num in group:
                lis.append(num)
                count+=1
                if count==k:
                    break
        return lis