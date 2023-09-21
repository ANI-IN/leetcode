class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        int start,end;
        int n=a.size();
         ans.push_back(a[0]);
        
        for(int i=1;i<n;i++)
        {
            int start=a[i][0];
            int end=a[i][1];
            
            
            if(ans.back()[1] < start)
            {
                ans.push_back(a[i]);
            }
            else
            {
                ans.back()[0]=min(ans.back()[0],start);
                ans.back()[1]=max(ans.back()[1],end);
            }
        }
        return ans;
        
        
    }
};