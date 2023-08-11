class Solution {
    int solve(int index, vector<int>&coins, int amount,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(amount%coins[0]==0)
                return 1;
            else
                return 0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        int non=solve(index-1,coins,amount,dp);
        int take=0;
    
        if(coins[index]<=amount)
            take=solve(index,coins,amount-coins[index],dp);
        
        return dp[index][amount]=non+take;
        
        
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        return solve(n-1,coins,amount,dp);
    }
};