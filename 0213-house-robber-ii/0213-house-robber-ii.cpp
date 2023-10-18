class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        vector<int> a1;
        vector<int> a2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                a1.push_back(nums[i]);
            
            if(i!=n-1)
                a2.push_back(nums[i]);
        }
        
        
        dp1[0]=a1[0];
        dp1[1]=max(a1[0],a1[1]);
        
        dp2[0]=a2[0];
        dp2[1]=max(a2[0],a2[1]);
        
        for(int i=2;i<a1.size();i++)
        {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + a1[i]);
        }
        
        for(int i=2;i<a2.size();i++)
        {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + a2[i]);
        }
                    
        return max(dp1[n-2],dp2[n-2]);
  
    }
};