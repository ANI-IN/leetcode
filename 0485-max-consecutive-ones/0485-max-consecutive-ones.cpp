class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                c++;
            }
            else
            {
                ans=max(ans,c);
                c=0;
            }
        }
        return max(ans,c);
        
    }
};