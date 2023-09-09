class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        
         for(auto it : edges)
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[i][k]==1e9 || dis[k][j]==1e9)
                        continue;
                    if(dis[i][k]+dis[k][j]<dis[i][j])
                    {
                      dis[i][j] = dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        
        int maxi=n;
        int city=0;
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]<=t)
                    c++;
            }
            if(maxi>=c)
            {
                maxi=c;
                city=i;
            }
        }
        return city;
    }
};