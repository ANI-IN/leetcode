class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        
        for(auto it : graph)
        {
            int u=it[0];
            int v=it[1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int ans=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans++;
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        if(ans==n)
            return true;
        else
            return false;
    }
};