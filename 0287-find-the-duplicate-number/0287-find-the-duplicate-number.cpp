class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,0);
        
        for(auto it : nums)
        {
            if(arr[it]>0)
                return it;
            else
                arr[it]++;
        }
        return -1;
    }
};