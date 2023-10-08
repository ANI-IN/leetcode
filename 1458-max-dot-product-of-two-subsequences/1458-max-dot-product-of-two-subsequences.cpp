class Solution {
    
    vector<vector<int>> dp;
    int md = 1e9+7;
    int n, m;
    
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2)
    {
        if(i == n || j == m)
            return -1e9;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int val = nums1[i] * nums2[j];
        
        int take = val + solve(i + 1, j + 1, nums1, nums2);
        
        int take_i = solve(i, j + 1, nums1, nums2);
        
        int take_j = solve(i + 1, j, nums1, nums2);
        
        return dp[i][j] = max({val, take, take_i, take_j});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, nums1, nums2);

        
        
    }
};