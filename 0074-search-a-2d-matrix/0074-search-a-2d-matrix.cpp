class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=n-1;
        int col=0;
        
        while(row>=0 && col<m)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                col++;
            }
            else
            {
                row--;
            }
        }
        return false;
    }
};