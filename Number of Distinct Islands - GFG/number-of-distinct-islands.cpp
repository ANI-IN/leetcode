//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void solve(int row, int col, vector<vector<int>>&vis, vector<pair<int,int>>&arr,vector<vector<int>>& grid,int br, int bc)
    {   
        vis[row][col]=1;
        arr.push_back({row-br,col-bc});
        int delrow[4]={-1,0,+1,0};
        int delcol[4]={0,-1,0,+1};
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<4;i++)
        {
            int nr=row+delrow[i];
            int nc=col+delcol[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
            {
                solve(nr,nc,vis,arr,grid,br,bc);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>> arr;
                    solve(i,j,vis,arr,grid,i,j);
                    ans.insert(arr);
                }
            }
        }
        
        
        return ans.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends