#define pb push_back

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret;
        // for (auto i=0; i<2;i++){
        //     for (auto num: nums){
        //         ret.pb(num);
        //     }
        // }
        // return ret;
        nums.insert(nums.end(), nums.begin(), nums.end());
        ret.insert(ret.end(), nums.begin(), nums.end());
        return ret;
    }
};