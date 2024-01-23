class Solution {
    void solve(int index, vector<int>&nums, set<vector<int>>&st, vector<int>&temp)
    {
        if(index==nums.size())
        {
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(index+1,nums,st,temp);
        temp.pop_back();
        solve(index+1,nums,st,temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,st,temp);
        
        for(auto it : st)
            ans.push_back(it);
        
        return ans;
        
    }
};