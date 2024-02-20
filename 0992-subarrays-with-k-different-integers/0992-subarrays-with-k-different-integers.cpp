class Solution {
    int solve(vector<int>&nums, int k)
    {
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        
        int ans=0;
        while(j<n)
        {
            m[nums[j]]++;
            
            if(m.size()>k)
            {
                while(m.size()>k)
                {
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
            }
            ans=ans+j-i+1;
            j++;
        }
        return ans;
        
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return solve(nums,k)-solve(nums,k-1);
    }
};