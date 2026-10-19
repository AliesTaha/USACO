class Solution {
public:
    int dp(int i, int num, vector<int>& arr, vector<int>& visited){
        if (visited[i]!=-1){
            return visited[i];
        }
        int curr=1;
        int maxi=1;

        for (int k=i; k<arr.size();k++){
            int nn=arr[k];
            if (nn>num){
                maxi=max(1+dp(k, nn, arr, visited), maxi);
            }
        }
        visited[i]=maxi;
        return visited[i];
     }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n, -1);

        int ret=1;
        for (int i=0;i<n;i++){
            ret=max(ret, dp(i, nums[i], nums, visited));
        }
        return ret;
    }
};