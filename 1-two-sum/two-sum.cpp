#define pb push_back
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  dic;
        for (int i=0; i<nums.size(); i++){
            int num=nums[i];
            int need=target-num;
            if (dic.count(need)){
                return {dic[need], i};
            }
            dic[num]=i;
        }
        return {};
    }
};