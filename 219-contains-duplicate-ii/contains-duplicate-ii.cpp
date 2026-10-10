class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> dic;
        for (int i =0; i<nums.size(); i++){
            int num=nums[i];
            dic[num].push_back(i);
        }
        for (auto& [key,v]: dic){
            for (int i=0; i<v.size()-1; i++){
                if ((v[i+1]-v[i])<=k){
                    return true;
                }
            }
        }
        return false;
    }
};