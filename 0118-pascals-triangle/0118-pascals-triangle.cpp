class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
           vector<int> temp;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || i==j)
                    temp.push_back(1);
                else
                    temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};