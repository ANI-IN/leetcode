class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0,high=m-1;
        
        while(low<=high)
        {
            int col=low+(high-low)/2;
            
            int maxi=0;
            int row=-1;
            for(int i=0;i<n;i++)
            {
                if(mat[i][col] > maxi)
                {
                    maxi=mat[i][col];
                    row=i;
                }
            }
            int curr=mat[row][col];
            int left=col==0?-1:mat[row][col-1];
            int right=col==m-1?-1:mat[row][col+1];
            
            if(curr>left && curr>right)
            {
                return {row,col};
            }
            else if(curr<left)
            {
                high=col-1;
            }
            else
            {
                low=col+1;
            }
        }
        return {-1,-1};
    }
};