class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        unordered_map<int,int>m;
        for(auto it : nums)
        {
            m[it]++;
        }
        
        for(auto it : m )
        {
            int x=it.second;
            s+=x*(x-1)/2;
        }
        return s;
    }
};