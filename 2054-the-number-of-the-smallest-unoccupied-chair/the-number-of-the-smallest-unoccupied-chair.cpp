class Solution {
public:
    vector<vector<int>> times;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        this->times=times;
        int n=times.size();
        vector<int> order(n);
        vector<int> chairs(n, 0);
        iota(order.begin(), order.end(), 0);

        auto comp= [&times](int& a, int& b){
            if (times[a][0]<times[b][0]){
            return true;
            }
            if (times[a][0]==times[b][0]&&times[a][1]<times[b][1]){
                return true;
            }
            return false;
        };

        sort(order.begin(), order.end(), comp);

        for (int i=0; i<=n; i++){
            int friendIdx=order[i];
            vector<int> time=times[friendIdx];
            int a=time[0], b=time[1];
            //go through chairs
            for (int k=0; k<n;k++){
                if (chairs[k]<=a){
                    chairs[k]=b;
                    if (friendIdx==targetFriend){
                        return k;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};