class Solution {
    bool valid (vector<int>&nums, int p, int mid)
    {
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=mid)
            {
                p--;
                i++;
            }
        }
        
        if(p>0)
            return false;
        else
            return true;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int low=0,high=nums[n-1];
        int ans=nums[n-1]-nums[0];
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(nums,p,mid))
            {   
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};