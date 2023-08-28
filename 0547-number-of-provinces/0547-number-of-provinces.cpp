class Solution {
    void dfs(int i, vector<int>&vis,vector<vector<int>>&a)
    {
        vis[i]=1;
        
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]==1 && !vis[j])
                dfs(j,vis,a);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> vis(n,0);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,vis,a);
            }
                
        }
        return ans;
    }
};