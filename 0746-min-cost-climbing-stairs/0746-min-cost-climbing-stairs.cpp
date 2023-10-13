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
        
       int x = cost[0];
       int y = cost[1];
        
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            int current=cost[i]+min(x,y);
            x=y;
            y=current;
        }
        
        return min(x,y);
        
         
        
        
    }
};