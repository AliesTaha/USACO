class FoodRatings {
public:
    struct comp{
        bool operator()(pair<int, string> a, pair<int, string> b) const{
            int arating=a.first;
            int brating=b.first;
            
            string afood=a.second;
            string bfood=b.second;
            if (arating<brating){
                return false;
            }
            if (arating>brating){ //maxheap
                return true;
            }
            int alength=afood.size();
            int blength=afood.size();
            for (int i=0; i<min(alength, blength); i++){
                if ((afood[i]-'a') != (bfood[i]-'a')){
                    return afood[i]<bfood[i];
                }
            }
            return (alength<blength);
        }
    };
    vector<int> ratings;
    vector<string> cuisines;
    unordered_map<string, set<pair<int, string>, comp>> cuisine_order;
    unordered_map<string, int> food2idx;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->ratings=ratings;
        this->cuisines=cuisines;
        for (int i=0; i<ratings.size(); i++){
            food2idx[foods[i]]=i;
        }
        //the cuisines to ordered set...note by default ordered sets are integers
        for (int i=0; i<ratings.size(); i++){
            pair<int, string> tup={ratings[i], foods[i]};
            cuisine_order[cuisines[i]].insert(tup);
        }
    }
    void changeRating(string food, int newRating) {
        int idx=food2idx[food];
        int old_rating=ratings[idx];
        pair<int, string> tup={old_rating,food};
        pair<int, string> ntup={newRating, food};

        cuisine_order[cuisines[idx]].erase(tup);
        cuisine_order[cuisines[idx]].insert(ntup);
        ratings[idx]=newRating;

    }
    string highestRated(string cuisine) {
        string food=cuisine_order[cuisine].begin()->second;
        return food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */