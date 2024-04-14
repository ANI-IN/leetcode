class Solution {
    int solve(vector<int>& nums,int k)
    {
        int sum=nums[0];
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        
        while(j<n)
        {
            if(sum>k)
            {
                while(i<j && sum>k)
                {
                    sum=sum-nums[i];
                    i++;
                }
            }
            if(sum==k)
                ans=ans+(j-i+1);
      
            j++;
            sum=sum+nums[j]; 
        }
        
        return ans;
    }
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int sum=0;
        m[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {   
            sum+=nums[i];
            
            int rem=sum-k;
            
            ans+=m[rem];
            
            
            m[sum]++;
        }
        return ans;
    }
};