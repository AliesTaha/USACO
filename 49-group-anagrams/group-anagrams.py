class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic=defaultdict(list)
        for word in strs:
            in_order=tuple(sorted(word))
            dic[in_order].append(word)
        return list(dic.values())