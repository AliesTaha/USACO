#define pb push_back
class Solution {
public:
    map<char, int> setfy(string str){
        map<char, int> s;
        for (auto c:str){
            s[c]+=1;
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> dic;
        for (auto st:strs){
            map<char,int> s=setfy(st);
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