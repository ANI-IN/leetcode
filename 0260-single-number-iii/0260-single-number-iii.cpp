class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x=0;
        for(auto it : nums)
            x=x^it;
        
        long right=(x^(x-1))&x;
        
        int one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&right)
                one=one^nums[i];
            else
                two=two^nums[i];
        }
        return {one,two};
            
    }
};