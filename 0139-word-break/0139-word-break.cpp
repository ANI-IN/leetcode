class Solution {
    bool solve(int index, string &s, vector<string>&dic, set<string>&st,vector<int>&dp)
    {
        if(index==s.size())
            return true;
        
        if(dp[index]!=-1)
            return dp[index];
        
        string temp;
        for(int i=index;i<s.size();i++)
        {
            temp=temp+s[i];
            if(st.find(temp)!=st.end())
            {
                if(solve(i+1,s,dic,st,dp)==true)
                    return dp[index]=true;
            }
        }
         return dp[index]= false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n,-1);
        
        set<string> st;
        for(auto it : wordDict)
        {
            st.insert(it);
        }
        int index=0;
        
        return solve(index,s,wordDict,st,dp);
    }
};