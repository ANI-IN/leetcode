class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string> a, const pair<int,string> b) const {
            if (a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
        }
    };
    map<string,string> foodToCus;
    map<string,int> rating;
    map<string,set<pair<int,string>,cmp>> cus;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCus[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
            cus[cuisines[i]].insert({ratings[i],foods[i]});
        }

    }
    
    void changeRating(string food, int newRating) {
        string c = foodToCus[food];
        auto old = make_pair(rating[food], food);
        rating[food] = newRating;
        cus[c].erase(old);
        cus[c].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto it = *cus[cuisine].rbegin();
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */