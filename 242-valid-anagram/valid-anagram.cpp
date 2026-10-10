class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;
        unordered_map<char, int> dic1;
        unordered_map<char, int> dic2;
        for (auto c: s){
            if (dic1.find(c)!=dic1.end()){
                dic1[c]+=1;
            }
            else{
                dic1[c]=1;
            }
        }
        for (auto c: t){
            if (dic2.find(c)!=dic2.end()){
                dic2[c]+=1;
            }
            else{
                dic2[c]=1;
            }
        }
        return dic1==dic2;
    }
};