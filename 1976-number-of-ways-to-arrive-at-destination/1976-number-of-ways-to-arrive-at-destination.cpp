class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<pair<long long,long long>> adj[n];
        vector<long long> distance(n,LONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long ,long long>, vector<pair<long long ,long long>>, greater<pair<long long ,long long>>> q;
        
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        distance[0]=0;
        ways[0]=1;
        
        q.push({0,0});
        
        while(!q.empty())
        {
            auto it =q.top();
            q.pop();
            long long dis=it.first;
            long long node=it.second;
            
            for(auto it : adj[node])
            {
                long long wt=it.second;
                long long adjnode=it.first;
                
                if(dis + wt < distance[adjnode])
                {
                    distance[adjnode]=dis+wt;
                    q.push({distance[adjnode],adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dis + wt== distance[adjnode])
                {
                     ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
                return ways[n-1];

    }
};