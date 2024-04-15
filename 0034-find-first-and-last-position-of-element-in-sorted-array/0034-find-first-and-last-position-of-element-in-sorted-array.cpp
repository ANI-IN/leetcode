class Solution {
    void solve(vector<int>&nums, int &first,int x)
    {
        int n=nums.size();
        int low=0,high=n-1;
        
        while(low<=high)
        {   
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    
    void solve1(vector<int>&nums, int &last, int x)
    {
        int n=nums.size();
        int low=0,high=n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==x)
            {
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        
        int first=-1,last=-1;
        solve(nums,first,target);
        solve1(nums,last,target);
        
        return {first,last};
    }
};