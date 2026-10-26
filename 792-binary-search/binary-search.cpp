class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mp,l,r;
        l=0; r=nums.size()-1;
        while (l<=r){
            mp=(l+r)/2;
            if (nums[mp]==target){
                return mp;
            }
            else if (nums[mp]>target){
                r=mp-1;
            }
            else{
                l=mp+1;
            }
        }
        return -1;
    }
};