class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==1){
            if (nums[0]==target){
                return 0;
            }
        }
        int n=nums.size()-1;
        int curr=0;
        for (int i=n; i>0; i=i>>1){
            cout<<nums[curr]<<endl;
            if (nums[curr]==target){
                return curr;
            }
            while ((curr+i)<=n && nums[curr+i]<=target){
                curr+=i;
                cout<<nums[curr]<<endl;
                if (nums[curr]==target){
                    return curr;
                }
            }
        }
        return -1;
    }
};