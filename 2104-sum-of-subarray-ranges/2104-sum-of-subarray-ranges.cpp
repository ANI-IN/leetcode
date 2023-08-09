class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
      long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int a=INT_MIN;
            int b=INT_MAX;
            for(int j=i;j<nums.size();j++)
            {
                a=max(a,nums[j]);
                b=min(b,nums[j]);
                sum=sum+abs(b-a);
            }
        }
        return sum;  
    }
};