class Solution {
    int mod=1e9+7;
public:
    int countHomogenous(string s) {
        int n=s.size();
        int count=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            ans=(ans+count)%mod;
        }
        return ans;
    }
};