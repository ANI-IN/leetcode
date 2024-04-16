class Solution {
    double solve(vector<int>&nums, int d)
    {
        int n=nums.size();
        double ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=ans+ceil((double)nums[i]/(double)d);
        }
        return ans;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double divisor=solve(nums,mid);
            
            if(divisor<=threshold)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
            
    }
};