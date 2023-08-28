class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>>q;        //time, {i,j}
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {   
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,+1,0,-1};
        
        int ans=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            ans=max(ans,time);
            for(int i=0;i<4;i++)
            {
                int nrow= row + delrow[i];
                int ncol= col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    return -1;    
            }
        }
        return ans;
    }
};