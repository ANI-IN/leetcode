class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int l=arr[i];
            
           m[l].push_back(i);
            if(m[l].size()==l)
            {
                ans.push_back(m[l]);
                  m[l].clear();
            }
        }
        return ans;
    }
};