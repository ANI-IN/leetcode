class Solution {
    void solve(int index,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(index>= arr.size() || target<0)
            return;
        
        for(int i=index;i<arr.size();i++)
        {
            if(i>index && arr[i]==arr[i-1])
                continue;
            

            temp.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],ans,temp);
            temp.pop_back();
            
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index=0;
        sort(candidates.begin(),candidates.end());
        solve(index,candidates,target,ans,temp);
        return ans;
    }
};