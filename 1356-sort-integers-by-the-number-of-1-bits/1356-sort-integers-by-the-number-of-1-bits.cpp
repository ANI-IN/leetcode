class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda=[&](int &ca, int &cb)
        {
            int a=__builtin_popcount(ca);
            int b=__builtin_popcount(cb);
            if(a==b)
                return ca<cb;
            
            return a<b;
        };
        
        
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};