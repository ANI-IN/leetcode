class Solution {
public:
 int dp[(int)1e5 + 1][27];
    int fun(int n, string &s, int k, char prev) {
        if (n < 0)
            return 0;

int res=0;
        if (dp[n][prev-'`'] != -1)
            return dp[n][prev-'`'];
         res = fun(n - 1, s, k, prev);


        if (prev == '`' || abs(s[n] - prev) <= k)
            res = max(res, 1 + fun(n - 1, s, k, s[n]));

        return dp[n][prev-'`'] = res;
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
         memset(dp, -1, sizeof dp);
      //  vector<vector<int>> dp((int)1e5+1 , vector<int>(27, -1));
        return fun(n - 1, s, k, '`');
    }
};