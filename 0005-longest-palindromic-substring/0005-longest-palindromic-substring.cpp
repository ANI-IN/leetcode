class Solution {
    int t[1001][1001];
    bool solve(string &s, int l, int r){
        if(l >= r) 
            return 1;

        if(t[l][r] != -1){
            return t[l][r];
        }

        if(s[l] == s[r]) {
            return t[l][r] = solve(s, l+1, r-1);
        }

        return t[l][r] = false;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=INT_MIN;
        int index=0;
        
        memset(t, -1, sizeof(t));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(s,i,j))
                {
                   if(maxi<j-i+1)
                   {
                       maxi=j-i+1;
                       index=i;
                   }
                }
            }
        }
        
        return s.substr(index,maxi);
    }
};