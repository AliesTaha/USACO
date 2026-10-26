#define pb push_back
class AuthenticationManager {
public:
    struct Token{
        string id;
        int begin;
        int end;
    };
    unordered_map<string, Token> dic;
    vector<Token*> heap;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    static bool compara(const Token* a, const Token* b){
        return (a->end>b->end);
    }

    void generate(string tokenId, int currentTime) {
        Token t{tokenId, currentTime, currentTime+ttl};
        dic[tokenId]=t;
        Token* tok= &dic[tokenId];
        heap.pb(tok);
        push_heap(heap.begin(), heap.end(), compara);
    }
    
    void renew(string tokenId, int currentTime) {
        if (dic.count(tokenId)==0 || dic[tokenId].end<=currentTime){
            return;
        }
        Token* t=&dic[tokenId];
        t->begin=currentTime;
        t->end=t->begin+ttl;
        make_heap(heap.begin(), heap.end(), compara);
    }
    
    int countUnexpiredTokens(int currentTime) {
        while (heap.size()>0){
            Token* t=heap[0];
            if ((t->end)<=currentTime){
                dic.erase(t->id);
                pop_heap(heap.begin(), heap.end(), compara);
                heap.pop_back();
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