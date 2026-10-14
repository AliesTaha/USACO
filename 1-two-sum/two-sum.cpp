class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        for(int i=0; i<nums.size(); i++){
            int num=nums[i];
            if (dic.count(target-num)){
                return {i, dic[target-num]};
            }
            dic[num]=i;
        }
        return {};
    }
};