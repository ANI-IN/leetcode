class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1;
        
        int left=0,right=m-1;
        
        
        int count=0;
        //condition no of element = n*m
        
        vector<int> ans;
        
        while(ans.size()<n*m)
        {
            for(int i=left;i<=right && ans.size()<n*m; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            
            for(int j=top+1;j<=bottom && ans.size()<n*m;j++)
            {
                ans.push_back(matrix[j][right]);
            }
            
            for(int i=right-1;i>=left && ans.size()<n*m;i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            
            for(int j=bottom-1;j>=top+1 && ans.size()<n*m;j--)
            {
                ans.push_back(matrix[j][left]);
            }
            
            left++;
            right--;
            bottom--;    
            top++;    
        }
        return ans;
    }
};