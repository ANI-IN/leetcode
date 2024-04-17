class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0,high=m-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int maxi=0;
            int row=-1;
            for(int i=0;i<n;i++)
            {
                if(mat[i][mid] > maxi)
                {
                    maxi=mat[i][mid];
                    row=i;
                }
            }
            int curr=mat[row][mid];
            int left=mid==0?-1:mat[row][mid-1];
            int right=mid==m-1?-1:mat[row][mid+1];
            
            if(curr>left && curr>right)
            {
                return {row,mid};
            }
            else if(curr<left)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};