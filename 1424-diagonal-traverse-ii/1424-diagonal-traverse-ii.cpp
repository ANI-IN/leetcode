class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
         vector<vector<int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                v.push_back({i+j,j,nums[i][j]});
            }
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i][2]);
        }
        return ans;
    }
};