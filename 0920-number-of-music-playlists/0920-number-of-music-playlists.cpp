class Solution {
    int mod = 1e9 + 7;
public:
    long long int solve(int n, int k, int goal,vector<vector<int>>&dp)
    {
        if(n==0 && goal==0)
            return 1;
        
        if(n==0 || goal==0)
            return 0;
        
        if(dp[n][goal]!=-1)
            return dp[n][goal];
        
        long long int pick=solve(n-1,k,goal-1,dp)*n;
        long long int non=solve(n,k,goal-1,dp)*max(n - k, 0);
        
        return dp[n][goal]=(pick+non)%mod;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1,vector<int>(goal+1,-1));
        return solve(n,k,goal,dp);
    }
};