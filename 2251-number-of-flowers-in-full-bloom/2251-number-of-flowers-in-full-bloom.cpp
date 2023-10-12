class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       int n = flowers.size();
        int an = people.size();
        vector<int>ans;
        vector<long long int>start,endi;
        for(int i = 0; i < flowers.size(); i++){
            start.push_back(flowers[i][0]);
            endi.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(endi.begin(),endi.end());

        for(int i = 0; i < an; i++){
            int k = people[i];
            auto it1 = upper_bound(start.begin(),start.end(),k);
            auto it2 = lower_bound(endi.begin(),endi.end(),k);
            int a = n - (it1-start.begin());
            int b = n - (it2-endi.begin());
            ans.push_back(abs(a-b));
        }
        return ans; 
    }
};