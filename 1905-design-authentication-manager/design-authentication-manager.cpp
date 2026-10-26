#define pb push_back
class AuthenticationManager {
public:
    struct Token{
        string id;
        int begin;
        int end;
    };
    unordered_map<string, Token> dic;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        Token t{tokenId, currentTime, currentTime+ttl};
        dic[tokenId]=t;
    }
    
    void renew(string tokenId, int currentTime) {
        if (dic.count(tokenId)==0 || dic[tokenId].end<=currentTime){
            return;
        }
        Token* t=&dic[tokenId];
        t->begin=currentTime;
        t->end=t->begin+ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it=dic.begin();
        while (it!=dic.end()){
            string key=it->first;
            Token t=it->second;
            if (t.end<=currentTime){
                it=dic.erase(it);
            }
            else{
                it++;
            }
        }
        return int(dic.size());
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */