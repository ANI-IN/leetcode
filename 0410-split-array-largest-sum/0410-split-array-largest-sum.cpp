class Solution {
    bool solve(vector<int>&nums, int k, int mid)
    {
        int sum=0;
        int n=nums.size();
        int c=1;
        
        for(int i=0;i<n;i++)
        {
            if(sum+nums[i]<=mid)
            {
                sum+=nums[i];
            }
            else
            {
                c++;
                sum=nums[i];
            }
        }
            
        return c>k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
    
            
        while(low<=high)
        {
            int mid=low+(high-low)/2;
        
            if(solve(nums,k,mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    
    }
};