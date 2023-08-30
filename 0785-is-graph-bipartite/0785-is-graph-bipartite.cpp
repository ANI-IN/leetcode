class Solution {
    bool solve(int node, int col, vector<int>&color,vector<int> adj[])
    {
        color[node]=col;
        
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
                if(solve(it,!col,color,adj)==false)
                    return false;    
            }
            else if(color[it]==col)
                    return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(auto it : graph[i])
            {
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(solve(i,0,col,adj)==false)
                    return false;
            }
        }
        return true;
    }
};