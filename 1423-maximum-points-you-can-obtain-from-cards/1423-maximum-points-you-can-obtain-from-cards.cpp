class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        
        int sum=0;
        
        for(int i=0;i<k;i++)
            sum+=nums[i];
        
        int maxi=sum;
        
        for(int i=k-1;i>=0;i--)
        {
            sum=sum-nums[i];
            sum=sum+nums[n-k+i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};