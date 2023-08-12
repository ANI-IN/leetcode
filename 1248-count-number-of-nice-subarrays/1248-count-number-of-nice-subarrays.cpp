class Solution {
    int solve(vector<int>&nums,int k)
    {
        int c=0,i=0,j=0,n=nums.size();
        int ans=0;
        while(j<n)
        {
            if(nums[j]%2==1)
                c++;
            if(c>k)
            {
                while(c>k)
                {
                    if(nums[i]%2==1)
                        c--;
                    i++;
                }
            }
            ans=ans+(j-i+1);
            j++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};