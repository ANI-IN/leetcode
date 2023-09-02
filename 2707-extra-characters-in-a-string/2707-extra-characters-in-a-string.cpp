class Solution {
    int solve(int index,string &s, unordered_map<string,int>&mpp,vector<int> &dp )
    {
        if(index>=s.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int ans=s.size();
        string str="";
        for(int i=index;i<s.size();i++)
        {
            str.push_back(s[i]);
            int count=str.size();
            if(mpp[str])
                count=0;
            
            count=count+solve(i+1,s,mpp,dp);
            ans=min(count,ans);
                
        }
        return dp[index]=ans;
        
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        unordered_map<string,int> mpp;
        vector<int> dp(n,-1);
        
        
        for(auto it : dictionary)
        {
            mpp[it]++;
        }
      return solve(0, s, mpp, dp); 
    }
};