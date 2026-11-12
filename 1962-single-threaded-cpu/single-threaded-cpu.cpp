#define pq priority_queue
#define pb push_back
    
class Solution {
    using Task=array<int, 3>;
    using ll= long long;
    struct comp_t{
        bool operator()(const Task& a,const Task& b) const{
            int a_time=a[0];
            int b_time=b[0];

            if (a_time>b_time){
                return true;
            }
            return false;
        }
    };

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
        pq<Task, vector<Task>, comp_t> t_minheap; 
        pq<Task, vector<Task>, comp_p> p_minheap; 
        vector<int> ret;

        for (int i=0; i<tasks.size(); i++){
            Task task_pair={tasks[i][0], tasks[i][1], i}; // qtime, proctime
            t_minheap.push(task_pair);
        }

        while (t_minheap.size()>0 || p_minheap.size()>0){
            // at current time, what are all available tasks 
            while (t_minheap.size()>0){
                Task taskpair=t_minheap.top();
                if (taskpair[0]<=t){
                    p_minheap.push(taskpair);
                    t_minheap.pop();
                }
                else{
                    break;
                }
            }
            if (p_minheap.empty() && !t_minheap.empty()) {
                t = t_minheap.top()[0];
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