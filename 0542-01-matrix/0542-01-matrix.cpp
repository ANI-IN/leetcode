class Solution {
    void solve(vector<vector<int>>&grid, vector<vector<int>> &ans, vector<vector<int>> &vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
                else
                {
                    vis[i][j]=0;
                }
            }
        }
        
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            ans[r][c]=d;
            
            for(int i=0;i<4;i++)
            {
                int nr=r+drow[i];
                int nc=c+dcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> grid=mat;
        
        solve(grid,ans,vis);
        return ans;
    }
};