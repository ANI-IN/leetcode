class Solution {
    int mod=1e9+7;
    int solve(int cell, vector<int> adj[],int n,vector<vector<int>>&dp)
    {
        if(n==0)
            return 1;
        int sum=0;
        
        if(dp[cell][n]!=-1)
            return dp[cell][n];

        for(auto it : adj[cell])
        {
            sum=(sum+solve(it,adj,n-1,dp))%mod;
        }
        return dp[cell][n]=sum;
    }
public:
    int knightDialer(int n) {
            
        vector<int> adj[10];  
        adj[0].push_back(4);
        adj[0].push_back(6);
        adj[1].push_back(6);
        adj[1].push_back(8);
        adj[2].push_back(7);
        adj[2].push_back(9);
        adj[3].push_back(4);
        adj[3].push_back(8);
        adj[4].push_back(3);
        adj[4].push_back(9);
        adj[4].push_back(0);
        adj[6].push_back(1);
        adj[6].push_back(7);
        adj[6].push_back(0);
        adj[7].push_back(2);
        adj[7].push_back(6);
        adj[8].push_back(1);
        adj[8].push_back(3);
        adj[9].push_back(4);
        adj[9].push_back(2);
        
        vector<vector<int>> dp(10,vector<int>(n,-1));
        int sum=0;
        for(int i=0;i<=9;i++)
        {
            sum=(sum+solve(i,adj,n-1,dp))%mod;
        }
        return sum;
    }
};