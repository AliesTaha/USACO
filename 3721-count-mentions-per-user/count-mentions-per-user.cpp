#define pb push_back
class Solution {
public:
    static bool comp(vector<string>& a, vector<string>& b){
        int t1= stoi(a[1]);
        int t2= stoi(b[1]);
        bool ret=false;
        if (t1<t2){
            ret=true;
        }
        if (t1==t2){
            if (a[0]=="OFFLINE"){
                return true;
            }
        }
        return ret;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> online_time(numberOfUsers, 0);
        vector<int> user_mentions(numberOfUsers, 0);

        sort(events.begin(), events.end(), comp);

        for (auto event : events){
            cout<<event[0]<<","<<event[1]<<" ";
        }
        for (vector<string> event:events){
            string kind=event[0];
            int timestamp=stoi(event[1]);
            if (kind=="MESSAGE"){
                //message event
                if (event[2]=="ALL"){
                    for (int id=0; id<numberOfUsers;++id){
                        user_mentions[id]+=1;
                    }
                }
                else if (event[2]=="HERE"){
                    for (int id=0; id<numberOfUsers;++id){
                        if (timestamp>=online_time[id]){
                            user_mentions[id]+=1;
                        }
                    }
                }
                else{
                    stringstream ss(event[2]);
                    string id;
                    vector<int> ids;
                    while (getline(ss, id, ' ')){
                        ids.pb(stoi(id.substr(2, id.size())));
                    }
                    for (int id: ids){
                        user_mentions[id]+=1;
                    }
                }
            }
            else{
                //offline event
                int id=stoi(event[2]);
                online_time[id]=timestamp+60;
            }
        }
        return user_mentions;
    }
};
