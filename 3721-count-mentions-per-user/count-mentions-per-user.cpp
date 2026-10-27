#define pb push_back
#define popb pop_back
class Solution {
public:
    vector<int> ret;
    struct Node{
        int id;
        int mentions;
        int back;
    };

    static bool comp(const Node& a, const Node& b){
        return a.back>b.back;
    }

    static bool vcomp(const vector<string>& a, const vector<string>& b){
        int ta=stoi(a[1]);
        int tb=stoi(b[1]);
        if (ta!=tb){
            return ta<tb;
        }
        else{
            return a[0]>b[0]; //offline first
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), vcomp);
        ret.resize(numberOfUsers, 0);
        unordered_map<int, Node> dic;
        for (int i=0; i<numberOfUsers; i++){
            Node n{i, 0, 0};
            dic[i]=n;
        }
        vector<Node> heap;

        for (vector<string> v_string: events){
            string type, time, id;
            type=v_string[0]; time=v_string[1]; id=v_string[2];
            //step 1 : find and return all online users to list
            while(heap.size()>0){
                Node t=heap[0];
                if (t.back<=stoi(time)){
                    //back online
                    dic[t.id]=(t); //2n ... 
                    pop_heap(heap.begin(), heap.end(), comp);
                    heap.popb();
                }
                else{
                    break;
                }
            }
            if (type=="MESSAGE"){
                //step 2 : traverse each case
                if (id=="ALL"){
                    //traverse heap and ++ 
                    for (int i=0; i<heap.size(); i++){
                        Node* t=&heap[i];
                        t->mentions++;
                    }
                    //traverse set and ++
                    unordered_map<int, Node> new_dic;
                    for (auto it=dic.begin(); it!=dic.end(); it++){
                        int id=it->first;
                        Node t=it->second;
                        t.mentions++;
                        new_dic[id]=t;
                    }
                    dic=new_dic;
                }
                else if (id=="HERE"){
                    //traverse set and ++
                    unordered_map<int, Node> new_dic;
                    for (auto it=dic.begin(); it!=dic.end(); it++){
                        int id=it->first;
                        Node t=it->second;
                        t.mentions++;
                        new_dic[id]=t;
                    }
                    dic=new_dic;
                }
                else{
                    //split terms
                    stringstream ss(id);
                    string id;
                    vector<string> ids;
                    while (getline(ss, id, ' ')){
                        id=id.substr(2);
                        ids.pb(id);
                    }
                    //add only those terms if in set
                    for (auto str: ids){
                        int uid=stoi(str);
                        auto it=dic.find(uid);
                        if (it!=dic.end()){
                            it->second.mentions++;
                        }
                        else{
                            for (Node& node: heap){
                                if (node.id==uid){
                                    ++node.mentions;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            else{
                //going offline
                int back = stoi(time)+60;
                int uid=stoi(id);
                int mentions=dic[uid].mentions;
                Node n{uid, mentions, back};
                dic.erase(uid);
                heap.pb(n);
                push_heap(heap.begin(), heap.end(), comp);
            }
        }

        //traverse heap and add to ret
        for (int i=0; i<heap.size(); i++){
            Node* t=&heap[i];
            int id=t->id;
            int count=t->mentions;
            ret[id]=count;
        }
        //traverse set and ++
        for (auto it=dic.begin(); it!=dic.end(); it++){
            Node t= it->second;
            int id=t.id;
            int count=t.mentions;
            ret[id]=count;
        }

        return ret;
    }
};
