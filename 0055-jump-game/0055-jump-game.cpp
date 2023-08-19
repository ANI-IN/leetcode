class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        
        for(int i=0;i<n;i++)
        {
            if(s<0)
                return false;
            s=max(s,nums[i])-1;
        }
        return true;
    }
};