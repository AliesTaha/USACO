class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dic;
        for (auto num:nums){
            if (dic.count(num)){
                return true;
            }
            dic[num]=1;
        }
        return false;
    }
};