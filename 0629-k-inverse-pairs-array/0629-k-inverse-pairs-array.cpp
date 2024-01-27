class Solution {
    int mod=1e9+7;
    int dp[1001][1001];
    int solve(int n, int k)
    {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=0;
        for(int i=0;i<=min(k,n-1);i++)
        {
            ans=(ans+solve(n-1,k-i))%mod;
        }
        return dp[n][k]=(ans)%mod;
    }
public:
    int kInversePairs(int n, int k) {
        
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};