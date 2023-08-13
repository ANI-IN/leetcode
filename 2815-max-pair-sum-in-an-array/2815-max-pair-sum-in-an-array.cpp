class Solution {
    int digit(int num)
    {
        int maxi=0;
        while(num)
        {
            maxi=max(maxi,num%10);
            num=num/10;
        }
        return maxi;
    }
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int n1=nums[i];
                int n2=nums[j];
                
                if(digit(n1)==digit(n2))
                {
                    ans=max(ans,n1+n2);
                }
            }
        }
        return ans;
    }
};