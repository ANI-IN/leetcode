class Solution {
    int solve(int i, vector<vector<int>>&mat)
    {
        int low=0,high=mat[0].size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(mat[i][mid]==1)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      int n=mat.size();
      
        vector<pair<int, int>> res;
        
        for(int i=0;i<n;i++)
        {
            int c=solve(i,mat);
            res.push_back({c, i});
        }
        sort(res.begin(),res.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++)
        {
            ans[i]=res[i].second;
        }
        return ans;
    }
};