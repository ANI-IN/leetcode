class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(auto it : nums)
            m[it]++;
        
        int maxi=0;
        int e=0;
        for(auto it : m)
        {
            int ee=it.first;
            int f=it.second;
            
            if(maxi<f)
            {
                e=ee;
                maxi=f;
            }
        }
        
        int res=0;
        for(auto it : m)
        {
            if(maxi==it.second)
            {
                res+=it.second;
            }
        }
        return res;
        
        
    }
};