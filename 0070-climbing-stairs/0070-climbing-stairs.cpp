class Solution {
    int solve(int index, vector<int>&dp)
    {
        if(index==0 || index==1)
            return 1;
        
        if(dp[index]!=-1)
            return dp[index];
        
        return dp[index]=solve(index-1,dp)+solve(index-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        return solve(n,dp);
    }
};