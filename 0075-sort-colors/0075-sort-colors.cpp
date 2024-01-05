class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i=0,mid=0,j=nums.size()-1;
        
        while(mid<=j)
        {
            if(nums[mid]==0)
            {
                swap(nums[i],nums[mid]);
                i++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[j],nums[mid]);
                j--;
            }
        }
    }
};