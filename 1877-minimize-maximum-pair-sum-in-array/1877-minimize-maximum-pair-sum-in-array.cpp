class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int n=nums.size();
        int ans=0;
        while(i<n && j>=0)
        {
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};