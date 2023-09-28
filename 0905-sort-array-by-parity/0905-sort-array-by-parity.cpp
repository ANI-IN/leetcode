class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n);
        int i=0,j=n-1;
        
        int index=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[index++]=nums[i];
            }
            else
            {
                ans[j--]=nums[i];
            }
        }
        return ans;
        
        
    }
};