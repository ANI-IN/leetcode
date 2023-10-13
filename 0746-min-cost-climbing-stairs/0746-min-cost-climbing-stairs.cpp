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
        
        vector<int> dp(1001,0);
        
        
       dp[0]=cost[0];
       dp[1]=cost[1];
        
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n - 1], dp[n - 2]);
        
         
        
        
    }
};