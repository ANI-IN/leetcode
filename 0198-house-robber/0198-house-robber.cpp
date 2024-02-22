class Solution {
    int solve(int index, vector<int> &arr ,vector<int>&dp)
    {
        if(index<0)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        
        int non=0+solve(index-1,arr,dp);
        int take=INT_MIN;
            take=arr[index]+solve(index-2,arr,dp);
        
        return dp[index]=max(non,take);
        
    }
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,-1);
        return solve(nums.size()-1,nums,dp);
    }
};