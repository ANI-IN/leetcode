class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> m;
            
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                ans++;
            int rem=sum-k;
            if(m.find(rem)!=m.end())
            {
                ans=ans+m[rem];
            }
            
            m[sum]++;
        }
        return ans;
    }
};