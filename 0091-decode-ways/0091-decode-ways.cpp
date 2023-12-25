class Solution {
    int solve(int i,int n,string s,vector<int>&dp)
    {
        if(i==n)
            return 1;
        
        if(s[i]=='0')
            return 0;
        
        if(i==n-1)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        string temp=s.substr(i,2);
        int pick=solve(i+1,n,s,dp);
        
        int pick2=0;
        if(stoi(temp)<=26 && stoi(temp)>0)
        pick2=solve(i+2,n,s,dp);
        
        return dp[i]=pick+pick2;
    }
public:
    int numDecodings(string s) {
        
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,s,dp);
    }
};