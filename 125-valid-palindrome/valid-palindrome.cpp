class Solution {
public:
    bool isPalindrome(string s) {
        string stripped;
        for (auto c: s){
            if (isalnum(c)){
                stripped+=tolower(c);
            }
        }
        string original=stripped;
        reverse(stripped.begin(), stripped.end());
        cout<<original<<endl;
        cout<<stripped<<endl;
        return original==stripped;

    }
};