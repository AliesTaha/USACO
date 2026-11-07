class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int> order(n);
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

        priority_queue<int, vector<int>, greater<int>> available_chairs; //pq is maxheap
        for (int i=0; i<n; i++){
            available_chairs.push(i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied_chairs; //pq is maxheap


        for (int i=0; i<n; i++){
            int friendIdx=order[i];
            int a=times[friendIdx][0],b= times[friendIdx][1];
            
            //go through heap & pop all available ones
            while (occupied_chairs.size()>0){
                int exp=occupied_chairs.top().first;
                int id=occupied_chairs.top().second;
                if (exp<=a){ //it expired, pop
                    occupied_chairs.pop();
                    available_chairs.push(id);
                }
                else{
                    break;
                }
            }
            //go get next available chair
            int curr_id=available_chairs.top();
            available_chairs.pop();

            //push to minheap
            occupied_chairs.push({b, curr_id});
            if (friendIdx==targetFriend){
                return curr_id;
            }
        }
        return -1;
    }
};