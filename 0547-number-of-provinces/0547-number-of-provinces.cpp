class Solution {
    void dfs(int node, vector<int>&visited, vector<int> adj[])
    {
        visited[node]=1;
        for(auto adjNode : adj[node])
        {
            if(visited[adjNode]==0)
            {
                dfs(adjNode,visited,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int Number_of_Provinces=0;
        vector<int> visited(n,0);
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        for(int node=0 ; node<n ; node++)
        {   
            if( visited[node]==0 )
            {
                Number_of_Provinces++;
                dfs(node , visited , adj );   
            }
        }
        
        return Number_of_Provinces;
    }
};