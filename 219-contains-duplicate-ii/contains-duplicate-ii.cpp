class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        for (int i =0; i<nums.size(); i++){
            int num=nums[i];
            if (dic.count(num)){
                if ((i-dic[num])<=k){
                    return true;
                }
                else{
                    dic[num]=i;
                }
            }
            else{
                dic[num]=i;
            }
        }
        return false;
    }
};