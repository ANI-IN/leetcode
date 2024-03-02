class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        
        int s=0,e=n-1,pos=n-1;
        while(s<=e)
        {
            if(abs(nums[s]) < abs(nums[e]))
            {
                ans[pos--]=nums[e];
                e--;
            }
            else
            {
                ans[pos--]=nums[s];
                s++;
            }
        }
        return ans;
    }
};