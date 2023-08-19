class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(auto it : nums)
        {
            if(it%2==0)
                m[it]++;
        }
        
        priority_queue<pair<int,int>>q;
        for(auto it : m)
            q.push({it.second,it.first});
        int ans=-1;
        
        while(!q.empty())
        {
            auto it = q.top();
            ans=it.second;
            q.pop();
            
            if(q.top().first!=it.first)
                break;
        }
        return ans;
    }
};