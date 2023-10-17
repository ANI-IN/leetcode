class Solution {
    int solve(int n, vector<int>&dp)
    {
        if(n==0 || n==1)
            return 1; 
        
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};