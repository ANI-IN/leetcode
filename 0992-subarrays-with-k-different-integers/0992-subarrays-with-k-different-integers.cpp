class Solution {
    int solve(vector<int>&nums, int k)
    {
        int i=0,j=0,n=nums.size();
        unordered_map<int,int>m;
        int ans=0;
        while(j<n)
        {
            m[nums[j]]++;
            
            while(m.size()>k)
            {
                m[nums[i]]--;
                
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};