class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        
        
        int sum=0;
        int rem=0;
        int count=0;
        
        
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            rem=sum%k;
            
            if(rem<0)
            rem=rem+k;

            if(m.find(rem)!=m.end())
            {
                count+=m[rem];
            }
            m[rem]++;
        }
        return count;
        
    }
};