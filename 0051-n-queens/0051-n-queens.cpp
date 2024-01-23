class Solution {
    bool isvalid(int row,int col,vector<string>grid,int n)
    {
        int r=row;
        int c=col;
        
        while(row>=0 && col>=0)
        {
            if(grid[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row=r;
        col=c;
        
        while(col>=0)
        {
            if(grid[row][col]=='Q')
                return false;
            col--;
        }
        
        row=r;
        col=c;
        
        while(row<n && col>=0)
        {
            if(grid[row][col]=='Q')
                return false;
            col--;
            row++;
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
            if(isvalid(i,col,str,n))
            {
                str[i][col]='Q';
                solve(col+1,n,str,ans);
                str[i][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> str(n);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            str[i]=s;
        }
        
        solve(0,n,str,ans);
        return ans;
        
    }
};