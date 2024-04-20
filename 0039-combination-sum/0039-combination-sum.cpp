class Solution {
    void solve(int index,vector<int>&arr, vector<vector<int>>&ans,vector<int>&temp, int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(target<0 || index==arr.size() )
            return;
        
        temp.push_back(arr[index]);
        solve(index,arr,ans,temp,target-arr[index]);
        temp.pop_back();
        solve(index+1,arr,ans,temp,target);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> temp;
        solve(index,candidates,ans,temp,target);
        return ans;
        
    }
};