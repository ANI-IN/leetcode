class Solution {
    int solve(int n, vector<int>&nums, vector<int>&dp)
    {
        if(n==0)
            return nums[n];
        if(n<0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int p=nums[n]+solve(n-2,nums,dp);
        int no=solve(n-1,nums,dp);
        
        return dp[n]=max(p,no);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int> a1;
        vector<int> a2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                a1.push_back(nums[i]);
            
            if(i!=n-1)
                a2.push_back(nums[i]);
        }
        
        return max(solve(n-2,a1,dp1),solve(n-2,a2,dp2));
        
        
        
    }
};