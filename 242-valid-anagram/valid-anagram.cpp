class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        if (s.length()!=t.length()){
            return false;
        }
        unordered_map<char, int> counter;
        for (int i=0; i<s.length(); i++){
            counter[s[i]]++;
            counter[t[i]]--;
        }
        for (auto& [key, val]: counter){
            if (val!=0){
                return false;
            }
        }
        return true;
    }
};