class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1)
            return -1;
        int delrow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}}); 
        vector<vector<int>> dis(n,vector<int>(m,1e9));
         dis[0][0]=1;
        
        while(!q.empty())
        {
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1)
                return d;
            
            for(int i=0;i<8;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && d+1<dis[nr][nc] && grid[nr][nc]==0)
                {
                    q.push({d+1,{nr,nc}});
                    dis[nr][nc]=d+1;
                }
            }
        }
        return -1;

    }
};