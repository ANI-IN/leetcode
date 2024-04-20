class Solution {
    void solve(int index,vector<int>&nums,int sum, set<vector<int>>&st,vector<int> temp)
    {
        if(index==nums.size())
        {
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        solve(index+1,nums,sum,st,temp);
        temp.pop_back();
        solve(index+1,nums,sum,st,temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        int index=0;
        int sum=0;
        vector<int> temp;
        solve(index,nums,sum,ans,temp);
        
        vector<vector<int>>res;
        for(auto it : ans)
        {
            res.push_back(it);
        }
        return res;
        
    }
};