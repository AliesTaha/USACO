class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int delta, curr_min=prices[0], ret=0;
        for (int i=1; i<prices.size(); i++){
            if (prices[i]>=curr_min){
                delta=prices[i]-curr_min;
                ret=max(ret, delta);
            }
            else{
                curr_min=prices[i];
            }
        }
        return ret;
    }
};