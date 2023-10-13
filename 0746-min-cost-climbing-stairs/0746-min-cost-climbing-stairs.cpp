class Solution {
    
    int solve(int index,vector<int>& cost, vector<int>&dp )
    {
        if(index>=cost.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int one=cost[index]+solve(index+1,cost,dp);
        int two=cost[index]+solve(index+2,cost,dp);
        
        return dp[index]=min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(1001,-1);
        
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};