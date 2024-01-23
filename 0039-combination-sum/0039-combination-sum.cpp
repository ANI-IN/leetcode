class Solution {
    void solve(int index, vector<int>&temp, vector<int>&arr,int target,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        else if(target<0 || index==arr.size())
            return;
        else
        {
            temp.push_back(arr[index]);
            solve(index,temp,arr,target-arr[index],ans);
            temp.pop_back();
            solve(index+1,temp,arr,target,ans);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        int index=0;
        int n=arr.size();
        vector<int>temp;
        solve(0,temp,arr,target,ans);
        return ans;
    }
};