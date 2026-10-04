#define pb push_back

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret=nums;
        for (int num:nums){
            ret.pb(num);
        }        
        return ret;
    }
};