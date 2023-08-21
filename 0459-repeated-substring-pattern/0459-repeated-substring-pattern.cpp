class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>=1;i--)
        {
            if(n%i==0)
            {
                int t=n/i;
                string str=s.substr(0,i);
                string tt="";
                while(t--)
                {
                    tt+=str;
                }
                if(tt==s)
                    return true;
            }
        }
        return false;
    }
};