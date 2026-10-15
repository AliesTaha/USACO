class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> ms;
        unordered_multiset<char> mt;
        for (auto c: s){
            ms.insert(c);
        }
        for (auto c: t){
            mt.insert(c);
        }
        return ms==mt;
    }
};