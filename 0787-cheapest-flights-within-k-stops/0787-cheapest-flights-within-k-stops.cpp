class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        vector<int> dis(n,1e9);
        
        for(auto it : flights)
            {
                int u=it[0];
                int v=it[1];
                int w=it[2];
                
                adj[u].push_back({v,w});
            }
       
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        
        
        while(!q.empty())
        {
            int node=q.front().second.first;
            int kk=q.front().first;
            int dist=q.front().second.second;
            q.pop();
            
            if(kk>k)
                continue;
            
            for(auto it : adj[node])
            {
                int v=it.first;
                int w=it.second;
                
                if(dist + w < dis[v])
                {
                    dis[v]=dist+w;
                    q.push({kk+1,{v,dis[v]}});
                }
            }
        }
        
        if(dis[dst]==1e9)
            return -1;
        else
            return dis[dst];
       
            
                
        
        
        
        return 0;
        
    }
};