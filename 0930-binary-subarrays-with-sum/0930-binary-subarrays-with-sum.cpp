class Solution {
    int solve(vector<int>& nums, int goal)
    {
        if(goal<0)
            return 0;
        int i=0,j=0,n=nums.size();
        int sum=0;
        int ans=0;
        while(j<n)
        {
            sum=sum+nums[j];
            
            while(sum>goal && i <= j )
            {
                sum=sum-nums[i];
                i++;
            }
            
                ans += (j - i + 1);
            
            j++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return solve(nums,goal)-solve(nums,goal-1);
    }
};