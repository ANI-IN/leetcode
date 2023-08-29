class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        
        int mx=0;
        int ans=0;
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Y')
                res++;
            else
                res--;
            
            if(res > ans)
            {
                ans=res;
                mx=i+1;
            }
        }
        return mx;
    }
};