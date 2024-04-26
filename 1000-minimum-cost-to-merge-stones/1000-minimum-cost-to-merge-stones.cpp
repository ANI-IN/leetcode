class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        // If it's impossible to merge all piles into one
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        
        // Prefix sum array
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + stones[i - 1];
        }
        
        // DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Iterate over different lengths
        for (int len = k; len <= n; len++) {
            // Iterate over possible starting positions
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try all possible merge positions
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                
                // Add the cost of merging the piles from i to j
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += prefix_sum[j + 1] - prefix_sum[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};