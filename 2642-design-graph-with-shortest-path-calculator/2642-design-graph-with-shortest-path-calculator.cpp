class Graph {
    vector<pair<int,int>> adj[1001];
   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int N;
public:
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        
        adj[u].push_back({v,w});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> result(N,INT_MAX);
        
        result[node1]=0;
        pq.push({0,node1});
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjnode=it.first;
                int dist=it.second;
                
                if(d + dist < result[adjnode])
                {
                    result[adjnode]=d+dist;
                    pq.push({d+dist, adjnode});
                }
            }
        }
        
        if(result[node2]==INT_MAX)
            return -1;
        else
            return result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */