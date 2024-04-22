class Solution {
    bool valid(int row,int col,vector<string>&grid,int n)
    {
        int r=row;
        int c=col;
        
        while(r>=0 && c>=0)
        {
            if(grid[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        
        r=row;
        c=col;
        while(c>=0)
        {
            if(grid[r][c]=='Q')
                return false;
            c--;
        }
        
        
        r = row, c = col;
        while(r<n && c>=0)
        {
            if(grid[r][c]=='Q')
                return false;
            
            r++;
            c--;
        }
        
        return true;
        
    }
    
    void solve(int col, int n, vector<string>&str,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(str);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(valid(i,col,str,n))
            {
                str[i][col]='Q';
                solve(col+1,n,str,ans);
                str[i][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> str(n, string(n, '.')); // Initialize board with n strings of length n
        
        solve(0, n, str, ans);
        return ans;
    }
};