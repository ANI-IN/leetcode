class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        
        
        for(int i=0;i<nums.size();i++)
        {   
            int a=INT_MAX;
            int b=INT_MIN;
            for(int j=i;j<nums.size();j++)
            {   
                b=max(b,nums[j]);
                a=min(a,nums[j]);
                
                    ans=ans+abs(b-a);
            }
        }
        return ans;
    }
};