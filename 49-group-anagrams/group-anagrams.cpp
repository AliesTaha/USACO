#define pb push_back
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> dic;
        for (auto& st:strs){
            array<int, 26> arr{};
            for (auto c:st){
                arr[c-'a']++;
            }
            dic[arr].pb(st);
        }
        
        vector<vector<string>> ret;
        for (auto& [k,v]: dic){
            ret.pb(v);
        }
        return ret;
    }
};