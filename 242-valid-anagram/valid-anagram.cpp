class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        unordered_map<char, int> dic1;
        unordered_map<char, int> dic2;
        for (auto c: s){
            dic1[c]++;
        }
        for (auto c: t){
            dic2[c]++;
        }
        return dic1==dic2;
    }
};