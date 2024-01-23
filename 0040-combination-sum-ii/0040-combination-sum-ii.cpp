class Solution {
    void solve(int index, int sum, int target, vector<int>&c, vector<int>&temp,vector<vector<int>>&ans)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        
        if(sum>target)
            return;
        
        if(index>=c.size())
            return;
        
        
        
        for(int i=index;i<c.size();i++)
        {   
            if(i!=index && c[i]==c[i-1])
                continue;
            
            sum=sum+c[i];
            temp.push_back(c[i]);
            
            
            solve(i+1,sum,target,c,temp,ans);
            
            temp.pop_back();
            sum=sum-c[i];
        }
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(c.begin(),c.end());
        solve(0,0,target,c,temp,ans);
        return ans;
    }
};