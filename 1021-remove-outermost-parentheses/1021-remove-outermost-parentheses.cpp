class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
               
                
                if(c>=1)
                {
                    ans=ans+s[i];
                }
                
                c++;
                
                
            }else
            {
                
                
                if(c>=2)
                {
                    ans=ans+s[i];
                }
                c--;
                
                
            }
        }
        return ans;
    }
};