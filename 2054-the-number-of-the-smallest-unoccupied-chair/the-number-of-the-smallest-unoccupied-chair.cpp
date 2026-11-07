class Solution {
public:
    vector<vector<int>> times;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        this->times=times;
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

        set<int> available_chairs;
        for (int i=0; i<n; i++){
            available_chairs.insert(i);
        }

        set<pair<int, int>> min_heap;

        for (int i=0; i<n; i++){
            int friendIdx=order[i];
            vector<int> time=times[friendIdx];
            int a=time[0], b=time[1];
            
            //go through heap & pop all available ones
            while (min_heap.size()>0){
                int exp=min_heap.begin()->first;
                int id=min_heap.begin()->second;
                if (exp<=a){ //it expired, pop
                    min_heap.erase(min_heap.begin());
                    available_chairs.insert(id);
                }
                else{
                    break;
                }
            }
            //go get next available chair
            auto it=available_chairs.begin();
            int curr_id=*it;
            available_chairs.erase(it);

            //push to minheap
            min_heap.insert({b, curr_id});
            if (friendIdx==targetFriend){
                return curr_id;
            }
        }
        return -1;
    }
};