class Solution {
    void solve(int index, vector<int>&nums, vector<vector<int>>&ans,vector<int>&temp)
    {
        if(index==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        if(index>nums.size())
            return;
        solve(index+1,nums,ans,temp);
        temp.push_back(nums[index]);
        solve(index+1,nums,ans,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,ans,temp);
        return ans;
    }
};