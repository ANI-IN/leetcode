class Solution {
    bool solve(int index, vector<int>&nums,vector<int>&dp)
    {
        if(index==nums.size())
            return true;
        
        if(dp[index]!=-1)
            return dp[index];
        
        if(index+1<nums.size() && nums[index+1]==nums[index])
        {
            if(solve(index+2,nums,dp)==true)
                return dp[index]=true;
            if(index+2<nums.size() && nums[index]==nums[index+2])
            {
                if(solve(index+3,nums,dp)==true)
                  return dp[index]=true;
            }
        }
        if(index+2<nums.size() && nums[index+1]==nums[index]+1 && nums[index+2]==nums[index]+2)
        {
            if(solve(index+3,nums,dp)==true)
              return dp[index]=true;
        }
        return dp[index]=false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};