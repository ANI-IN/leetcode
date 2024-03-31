class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        
        int prevmin=-1;
        int prevmax=-1;
        long long ans=0;
        int j=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < minK || nums[i]>maxK)
                j=i;
            
            if(nums[i]==minK)
                prevmin=i;
            if(nums[i]==maxK)
                prevmax=i;
            
            ans=ans +max(0,min(prevmin,prevmax)-j);
        }
        return ans;
    }
};