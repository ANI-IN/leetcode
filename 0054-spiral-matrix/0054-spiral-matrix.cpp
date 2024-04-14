class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int count=0;
        vector<int> ans;
        
        int left=0,right=m-1,top=0,bot=n-1;
        
        while(ans.size()<n*m)
        {
            
            for(int i=left;i<=right && ans.size()<n*m;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            
            for(int j=top+1;j<=bot && ans.size()<n*m ;j++)
            {
                ans.push_back(matrix[j][right]);
            }
            
            for(int i=right-1;i>=left && ans.size()<n*m;i--)
            {
                ans.push_back(matrix[bot][i]);
            }
            
            for(int j=bot-1;j>=top+1 && ans.size()<n*m ; j--)
            {
                ans.push_back(matrix[j][left]);
            }
            
            left++;
            right--;
            top++;
            bot--;
        }
        return ans;
    }
};