#define pb push_back
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dic;
        for (auto& st:strs){
            // array<int, 26> arr{};
            // for (auto c:st){
            //     arr[c-'a']++;
            // }
            string arr = st;
            sort(st.begin(), st.end());
            dic[st].pb(arr);
        }
        
        vector<vector<string>> ret;
        for (auto& [k,v]: dic){
            ret.pb(v);
        }
        return ret;
    }
};