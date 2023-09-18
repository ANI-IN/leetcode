class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {   
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            q.push({count,i});
            
            if(q.size()>k)
                q.pop();
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int index=q.top().second;
            ans.push_back(index);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};