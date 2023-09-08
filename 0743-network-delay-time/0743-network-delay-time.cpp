class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        vector<int> dis(n+1,1e9);
        for(auto it : times)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
        }
        
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        
        while(!q.empty())
        {
            int node=q.top().second;
            int time=q.top().first;
            q.pop();
            
            for(auto it : adj[node])
            {   
                int v=it.first;
                int t=it.second;
                
                if(time + t < dis[v])
                {
                    dis[v]=time+t;
                    q.push({dis[v],v});
                }
            }
        }
        
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==1e9)
                return -1;
            else 
                maxi=max(maxi,dis[i]);
        }
        return maxi;
        
        
        
    }
};