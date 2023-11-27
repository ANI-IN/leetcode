class Solution {
    int solve(string &s, vector<vector<int>>&dp, int i, int j)
    {
        if(i>=j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j]=solve(s,dp,i+1,j-1);
        
        return dp[i][j] = 0;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        string ans="";
        int index=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(s,dp,i,j))
                {
                    if(maxi<j-i+1)
                    {
                       index=i;
                       maxi=j-i+1;
                    }
                }
            }
        }
        return s.substr(index,maxi);
        
        
    }
};