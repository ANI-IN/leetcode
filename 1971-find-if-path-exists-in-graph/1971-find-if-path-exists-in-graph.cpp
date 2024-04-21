class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue <int> q;
        vector <int> vis(n,0);
        vector <int> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vis[source]=1;
        q.push(source);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==destination)
                return true;
            for(auto it : adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
        
    }
};