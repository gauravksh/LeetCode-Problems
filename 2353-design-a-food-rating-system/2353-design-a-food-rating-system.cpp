class FoodRatings {
    unordered_map<string,set<pair<int,string>>> mp;
    unordered_map<string,int> rating;
    unordered_map<string,string> ftc;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            rating[foods[i]] = ratings[i];
            ftc[foods[i]] = cuisines[i];
            mp[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        mp[ftc[food]].erase({-rating[food], food});
        mp[ftc[food]].insert({-newRating, food});
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = mp[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */