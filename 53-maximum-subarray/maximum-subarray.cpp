class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max=nums[0], curr_sum=0;
        for (int i=0; i<nums.size(); i++){
            curr_sum=max(nums[i], curr_sum+nums[i]);
            curr_max=max(curr_max, curr_sum);
        }
        return curr_max;
    }
};