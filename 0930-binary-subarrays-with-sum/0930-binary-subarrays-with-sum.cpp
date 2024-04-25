class Solution {
    int solve(vector<int>&nums,int t)
    {
        int n=nums.size();
        int i=0,j=0,ans=0;
        int sum=0;
        while(j<n)
        {
            sum=sum+nums[j];
            
            while(sum>t && i<=j)
            {
                sum=sum-nums[i];
                i++;
            }
            
                ans=ans+(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};