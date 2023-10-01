class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int c=n/3;
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(auto it : nums)
        {
            m[it]++;
        }
        
        for(auto it : m)
        {
            if(it.second>c)
            {
                ans.push_back(it.first);
            }
            
        }
        return ans;
        
        
        
        
    }
};