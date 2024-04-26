class Solution {
private:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>&dp, int n, int m) {
        if (row == n - 1) {
            return grid[row][col];
        }

        if (dp[row][col]!= -1)
            return dp[row][col];

        int mini = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (i != col) {
                mini = min(mini,solve(row + 1, i, grid, dp, n, m));
            }
        }
        return dp[row][col] = grid[row][col]+mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int row = 0;
       
        int ans = INT_MAX;
        for (int c = 0; c < m; c++) {
            ans = min(ans, solve(row, c, grid, dp, n, m));
        }
        return ans;
    }
};