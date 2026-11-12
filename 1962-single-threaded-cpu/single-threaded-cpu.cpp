#define pq priority_queue
#define pb push_back
    
class Solution {
    using Task=array<int, 3>;
    using ll= long long;

    struct comp_p{
        bool operator()(const Task& a,const Task& b) const{
            int ap_time=a[1];
            int bp_time=b[1];
            if (ap_time!=bp_time){
                return a[1]>b[1];
            }
            return a[2]>b[2];
        }
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // int t=minimum time existing in tasks
        ll t=INT_MAX;
        int q_time;
        // tasks[i] = [enqueueTimei, processingTimei]
        for (auto& task: tasks){
            q_time=task[0];
            if (t>q_time){
                t=q_time;
            }
        }
        //t is at minimum time in our nodes

        // minheap(task_pairs) sorted by q_time
        // minheap(task_pairs) sorted by end_time
        vector<Task> t_min; 
        pq<Task, vector<Task>, comp_p> p_minheap; 
        vector<int> ret;

        for (int i=0; i<tasks.size(); i++){
            Task task_pair={tasks[i][0], tasks[i][1], i}; // qtime, proctime
            t_min.pb(task_pair);
        }
        sort(t_min.begin(), t_min.end());
        int i=0;

        while (ret.size()<t_min.size()){
            // at current time, what are all available tasks 
            while (i<t_min.size() && t_min[i][0]<=t){
                Task task=t_min[i];
                p_minheap.push(task);
                i+=1;
            }
            if (p_minheap.empty()) {
                t = t_min[i][0];
                continue;
            }
            Task curr_task=p_minheap.top();
            p_minheap.pop();
            
            int qtime, proctime;
            qtime=curr_task[0];
            proctime=curr_task[1];

            ret.pb(curr_task[2]); //pb the index of the curr task processed
            t+=proctime; //move time to after having processed this
        }
        return ret;
    }
};