class Solution {
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int island=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    island++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        
        return island;
    }
};