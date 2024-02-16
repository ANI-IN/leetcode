class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      
        long peri=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<sum)
            {
                ans=sum+nums[i];
            }
            sum=sum+nums[i];
        }
        return ans==0?-1:ans;
        
        
    }
};