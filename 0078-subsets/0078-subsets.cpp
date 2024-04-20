class Solution {
    void solve(int index,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        if(index>nums.size())
            return;
        
        temp.push_back(nums[index]);
        solve(index+1,nums,temp,ans);
        temp.pop_back();
        solve(index+1,nums,temp,ans);
       
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0,n=nums.size();
        vector<int> temp;
        
        solve(index,nums,temp,ans);
        return ans;
    }
};