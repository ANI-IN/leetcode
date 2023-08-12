class Solution {
    int solve(vector<int>&nums,int goal)
    {
        int i=0,j=0,n=nums.size();
        int res=0;
        int sum=0;
        if(goal<0)
            return 0;
        
        while(j<n)
        {
            sum+=nums[j];
            
            while(sum>goal)
            {
                sum=sum-nums[i];
                i++;;
            }
            
            res=res+j-i+1;
            j++;
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return solve(nums,goal)-solve(nums,goal-1);
    }
};