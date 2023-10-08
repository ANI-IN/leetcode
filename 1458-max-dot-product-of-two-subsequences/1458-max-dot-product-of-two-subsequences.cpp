class Solution {
    int solve(int i, int j, int n, int m,vector<int>& nums1,vector<int>& nums2,vector<vector<int>> &dp)
    {
        if(i==n || j==m)
            return -1e9;
        
        if(dp[i][j]!=-1e9)
            return dp[i][j];
        
        int val=nums1[i]*nums2[j];
        
        int take=nums1[i]*nums2[j]+solve(i+1,j+1,n,m,nums1,nums2,dp);
        
        int take_i=solve(i,j+1,n,m,nums1,nums2,dp);
        
        int take_j=solve(i+1,j,n,m,nums1,nums2,dp);
        
        return dp[i][j]=max({val,take,take_i,take_j});
        
        
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Create a dp table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
        
        // Initialize the dp table for the base case
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = -1e9;
                }
            }
        }
        
        // Fill in the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int val = nums1[i - 1] * nums2[j - 1];
                
                // Calculate the maximum dot product by considering various options
                dp[i][j] = max({val, dp[i - 1][j - 1] + val, dp[i - 1][j], dp[i][j - 1]});
            }
        }
        
        // The result is stored in dp[n][m]
        return dp[n][m];
    }
};