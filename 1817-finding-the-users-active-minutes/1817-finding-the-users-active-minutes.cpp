class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n=logs.size();
        
        
        unordered_map<int,set<int>> m;
        for(int i=0;i<n;i++)
        {
            int id=logs[i][0];
            int time=logs[i][1];
            
            m[id].insert(time);
        }
        
        vector<int> ans(k,0);
        for(auto it : m)
        {
            int min=it.second.size();
            if(min<=k)
            {
                ans[min-1]++;
            }
        }
        return ans;
    }
};