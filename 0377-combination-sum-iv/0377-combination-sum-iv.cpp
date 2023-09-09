class Solution {
    int solve(int index, int sum,vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(sum==target)
            return 1;
        if(sum>target || index>=nums.size())
            return 0;
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        int ways=0;
            
        for(int i=index;i<nums.size();i++)
        {
              ways+=solve(0,sum+nums[i],nums,target,dp);
        }
          
            
      return dp[index][sum]=ways;
        
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        int sum=0;
        return solve(0,sum,nums,target,dp);
    }
};