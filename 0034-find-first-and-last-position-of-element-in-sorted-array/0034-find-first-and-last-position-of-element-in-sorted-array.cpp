class Solution {
    int solve(vector<int>&nums,int target,int n)
    {
        int index=-1;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                index=mid;
                high=mid-1;
            }
            else if(nums[mid]<=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return index;
        
    }
    int solve1(vector<int>&nums,int target,int n)
    {
        int index=-1;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                index=mid;
                low=mid+1;
            }
            else if(nums[mid]<=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return index;
        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int f=solve(nums,target,n);
        int l=solve1(nums,target,n);
        vector<int> ans(2);
        ans[0]=f!=-1?f:-1;
        ans[1]=l!=-1?l:-1;
        
        return ans;
        
        
    }
};