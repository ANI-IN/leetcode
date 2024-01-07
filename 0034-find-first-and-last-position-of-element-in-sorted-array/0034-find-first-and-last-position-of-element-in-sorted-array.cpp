class Solution {
    int solve(vector<int>&nums,int x, int n)
    {
        int low=0,high=n-1;
        int index=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
            {
                index=mid;
                high=mid-1;
            }
            else if(nums[mid]<x)
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
    
    int solve2(vector<int>&nums,int x, int n)
    {
        int low=0,high=n-1;
        int index=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
            {
                index=mid;
                low=mid+1;;
            }
            else if(nums[mid]<x)
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
        vector<int> ans;
        
        int x=solve(nums,target,n);
        int y=solve2(nums,target,n);
        
        if(x!=-1 && y!=-1)
        {
            ans.push_back(x);
            ans.push_back(y);
            return ans;
        }
        
        return {-1,-1};
        
    }
};