class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        vector<int> ans(n);
        
        for(int k=0;k<n;k++)
        {
            if(nums[k]>0)
            {
                ans[i]=nums[k];
                i=i+2;
            }
            else
            {
                ans[j]=nums[k];
                j=j+2;
            }
        }
        return ans;
        
    }
};