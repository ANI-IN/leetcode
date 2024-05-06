class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0;
        int n=nums.size();
        int i=0,j=0,ans=0;
        
        while(j<n)
        {
            if(nums[j]==0)
                c++;
            
            while(c>k)
            {
                if(nums[i]==0)
                    c--;
                
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
            
        }
        return ans;
    }
};