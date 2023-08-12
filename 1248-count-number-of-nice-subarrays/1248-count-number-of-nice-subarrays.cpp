class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2==0?0:1;
        }
        
        for(auto it : nums)
            cout<<it;
        
        unordered_map<int,int>m;
        int i=0,j=0,n=nums.size(),ans=0;
        int sum=0;
        
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(m.find(sum-goal)!=m.end())
            {
                ans+=m[sum-goal];
            }
            m[sum]++;
        }
        return ans;
    }
};