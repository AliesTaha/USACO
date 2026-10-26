#define pb push_back

class AuthenticationManager {
public:
    struct Token{
        string id;
        int beg;
        int end;
    };
    
    // min heap
    static bool expiresLater(const Token* a, const Token* b) {
        return a->end > b->end;
    }
    unordered_map<string, Token> dic;
    vector<Token*> heap;
    int ttl;

    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        Token t{tokenId, currentTime, currentTime+ttl};
        dic[tokenId]=t;
        heap.pb(&dic[tokenId]);
        push_heap(heap.begin(), heap.end(), expiresLater);
    }
    
    void renew(string tokenId, int currentTime) {
        if (dic.find(tokenId)==dic.end()){
            return;
        }
        Token* t=&dic[tokenId];
        if (t->end<=currentTime){
            return;
        }
        t->beg=currentTime;
        t->end=t->beg+ttl;
        make_heap(heap.begin(), heap.end(), expiresLater);
    }
    
    int countUnexpiredTokens(int currentTime) {
        while (heap.size()>0){
            Token* t=heap[0];
            if (t->end<=currentTime){
                pop_heap(heap.begin(), heap.end(), expiresLater);
                heap.pop_back();
                dic.erase(t->id);
            }
            else{
                break;
            }
        }
        return heap.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */