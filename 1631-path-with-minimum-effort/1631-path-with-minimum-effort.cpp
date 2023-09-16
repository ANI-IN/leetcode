class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans=0;
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>> grid(n,vector<int>(m,1e9));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            
            int r=it.second.first;
            int c=it.second.second;
            int d=it.first;
            
            if(r==n-1 && c==m-1)
                return d;
            
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int maxi=max( abs(heights[r][c]-heights[nr][nc]) ,d );
                    
                    if(maxi<grid[nr][nc])
                    {
                        grid[nr][nc]=maxi;
                        q.push({maxi,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};