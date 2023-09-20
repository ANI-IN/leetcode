class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            m[sum]=i;
        }
        m[0]=-1;
        int target=sum-x;
        int len=INT_MIN;
        
        if(sum<x)
            return -1;
        sum=0;
        
        
       
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            int rem=sum-target;
            if(m.find(rem)!=m.end())
            {
                int idx=m[rem];
                len=max(len,i-idx);
            }
        }
        
        if(len==INT_MIN)
            return -1;
        else
            return n-len;
    }
};