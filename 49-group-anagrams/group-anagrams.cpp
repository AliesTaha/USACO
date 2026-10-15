#define pb push_back
class Solution {
public:
    multiset<char> setfy(string str){
        multiset<char> s;
        for (auto c:str){
            s.insert(c);
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, vector<string>> dic;
        for (auto st:strs){
            multiset s=setfy(st);
            dic[s].pb(st);
        }
        
        vector<vector<string>> ret;
        for (auto [k,v]: dic){
            vector<string> ret_;
            for (auto s: v){
                ret_.pb(s);
            }
            ret.pb(ret_);
        }
        return ret;
    }
};