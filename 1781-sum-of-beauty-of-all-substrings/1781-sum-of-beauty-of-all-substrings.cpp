class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<char,int> m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                
                int mf=0,lf=INT_MAX;
                for(auto it : m)
                {
                    mf=max(mf,it.second);
                    lf=min(lf,it.second);
                }
                ans+=mf-lf;
            }
            
        }
        return ans;
    }
};