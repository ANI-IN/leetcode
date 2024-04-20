class Solution {
    void bfs(int i, int j, vector<vector<int>>& land,vector<vector<int>>& vis,vector<vector<int>>& ans)
    {
        int n=land.size();
        int m=land[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        
        int top_left_row=i;
        int top_left_col=j;
        
        int bot_right_row=i;
        int bot_right_col=j;
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
           
            
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+r;
                int ncol=delcol[i]+c;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && land[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    
                    top_left_row = min(top_left_row, nrow);
                    top_left_col = min(top_left_col, ncol);
                    bot_right_row = max(bot_right_row, nrow);
                    bot_right_col = max(bot_right_col, ncol);
                }
            }
        }
        
        ans.push_back({top_left_row, top_left_col, bot_right_row, bot_right_col});
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1 && vis[i][j]==0)
                {
                    bfs(i,j,land,vis,ans);
                }
            }
        }
        return ans;
    }
};