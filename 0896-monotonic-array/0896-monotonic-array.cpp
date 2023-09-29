class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<3){return true;}
        int inc = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]!=nums[i-1] && inc==0){
                inc = nums[i]>nums[i-1]?1:-1;
            }
            if(nums[i]>nums[i-1] && inc==-1){
                return false;
            } else if(nums[i]<nums[i-1] && inc==1){
                return false;
            }
        }
        return true;
    }
};