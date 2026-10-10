#define pb push_back
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  dic;
        vector<int> pair;
        for (int i=0; i<nums.size(); i++){
            int num=nums[i];
            int need=target-num;
            if (dic.count(need)){
                pair.pb(dic[need]);
                pair.pb(i);
                return {dic[need], i};
            }
            dic[num]=i;
        }
        return pair;
    }
};