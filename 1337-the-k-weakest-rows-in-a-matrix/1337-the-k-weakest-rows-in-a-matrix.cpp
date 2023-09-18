class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            q.push({count,i});
             
            
        }
        
        vector<int> ans;
        
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
            
        }
        return ans;
    }
};