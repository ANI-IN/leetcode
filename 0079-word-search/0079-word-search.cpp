class Solution {
    bool solve(int i, int j, string word,vector<vector<char>>& board, int index)
    {
       if(index==word.size())
           return true;
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index])
            return false;
        
        board[i][j]='1';
        if( (solve(i+1,j,word,board,index+1) || solve(i,j+1,word,board,index+1) || solve(i-1,j,word,board,index+1) || solve(i,j-1,word,board,index+1))==true)
            return true;
        
        board[i][j]=word[index];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
         
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && solve(i,j,word,board,0))
                    return true;
            }
        }
        return false;
    }
};