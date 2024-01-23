class Solution {
    void solve(int index, int sum, int k, int n, vector<vector<int>>&ans, vector<int>&temp, int size)
    {
        if(size==k && sum==n)
        {
            ans.push_back(temp);
            return;
        }
        
        if(size>k || sum>n)
            return;
        
        for(int i=index;i<=9;i++)
        {
            sum=sum+i;
            temp.push_back(i);
            
            solve(i+1,sum,k,n,ans,temp,size+1);
            
            temp.pop_back();
            sum=sum-i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        int index=1;
        int sum=0;
        
        
        solve(index,sum,k,n,ans,temp,0);
    
        return ans;
    }
};