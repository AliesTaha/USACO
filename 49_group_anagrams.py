class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs_dic=defaultdict(list)
        for i, word in enumerate(strs):
            sorted_word=sorted(word)
            strs_dic[*sorted_word].append(word)
        
        return(list(strs_dic.values()))