#define pb push_back
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> dic;
        for (auto& st:strs){
            map<char, int> s;
            for (auto c:st){
                s[c]+=1;
            }
            dic[s].pb(st);
        }
        
        vector<vector<string>> ret;
        for (auto& [k,v]: dic){
            ret.pb(v);
        }
        return ret;
    }
};