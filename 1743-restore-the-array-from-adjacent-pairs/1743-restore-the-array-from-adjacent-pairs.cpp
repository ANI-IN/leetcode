class Solution {
    void solve(int node, int prev, unordered_map<int,vector<int>>&adj,vector<int>&ans)
    {
        ans.push_back(node);
        for(auto it : adj[node])
        {
            if(it!=prev)
            {
                solve(it,node,adj,ans);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
        unordered_map<int,vector<int>> adj;
        vector<int> ans;
        
        for(auto it : arr)
        {
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int start=-1;
        
        for(auto it : adj)
        {
            if(it.second.size()==1)
            {
                start=it.first;
                break;
            }
        }
        
        solve(start,INT_MIN,adj,ans);
        return ans;
    }
};