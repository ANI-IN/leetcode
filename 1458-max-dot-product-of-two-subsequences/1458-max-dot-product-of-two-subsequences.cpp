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
       int n = nums1.size();
        int m = nums2.size();
        
        vector<int> dp(m + 1, INT_MIN / 2); // Initialize with a large negative value
        
        for (int i = 0; i < n; i++) {
            int prev = dp[0];
            for (int j = 0; j < m; j++) {
                int val = nums1[i] * nums2[j];
                int tmp = dp[j + 1];
                dp[j + 1] = max({val, dp[j], dp[j + 1], prev + val});
                prev = tmp;
            }
        }
        
        return dp[m];

        
        
    }
};