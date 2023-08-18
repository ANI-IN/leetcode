class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> indegree(n);
        
        unordered_map<int,unordered_set<int>> adj;
        
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            
            adj[u].insert(v);
            adj[v].insert(u);
            
            indegree[u]++;
            indegree[v]++;
        }
         
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ii=adj[i].size();
                int jj=adj[j].size();
                
                int res=ii+jj;
                
                if(adj[i].find(j)!=adj[i].end())
                    res--;
                
                ans=max(ans,res);
            }
        }
        return ans;
        
    }
};
