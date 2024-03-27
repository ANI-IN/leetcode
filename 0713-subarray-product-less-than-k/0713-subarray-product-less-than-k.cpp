class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
          if (k <= 1) return 0;
        
        int n=nums.size();
        long long prod=1;
        int i=0,j=0;
        int ans=0;
        while(j<n)
        {
            prod=prod*nums[j];
            
            while(prod>=k)
            {
                prod=prod/nums[i];
                i++;
            }
            
            ans=ans+(j-i+1);
            j++;
        }
        return ans;
    }
};