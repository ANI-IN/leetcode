class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans=nums[k];
        int maxi=nums[k];
        int i=k;
        int j=k;
        int n=nums.size();
        
        
        while(i>0 || j<n-1)
        {
            int left=(i>0)?nums[i-1]:0;
            int right=(j<n)?nums[j+1]:0;
            
            if(left > right)
            {
                maxi=min(maxi,left);
                i--;
            }
            else
            {
                maxi=min(maxi,right);
                j++;
            }
            ans=max(ans,(j-i+1)*maxi);
        }
        return ans;
        
        
    }
};