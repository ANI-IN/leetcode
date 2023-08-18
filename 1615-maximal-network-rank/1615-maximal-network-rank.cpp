class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
                
        unordered_map<int,unordered_set<int>> adj;
        //using unordered set because to use find function in O(1) TC
        
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
         
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int indegree_i=adj[i].size();
                int indegree_j=adj[j].size();
                
                int res=indegree_i+indegree_j;
                
                if(adj[i].find(j)!=adj[i].end())
                    res--;
                
                ans=max(ans,res);
            }
        }
        return ans;
        
    }
};
