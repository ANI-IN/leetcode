class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda=[&](int &a, int &b){
            int ca=__builtin_popcount(a);
            int cb=__builtin_popcount(b);
            
            if(ca==cb)
                return a<b;
            
            return ca<cb;
        };
        
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};