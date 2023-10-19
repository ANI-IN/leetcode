class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1="";
        string str2="";
        int n=s.size();
        int m=t.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
                str1.push_back(s[i]);
            else
            {
                if(!str1.empty())
                    str1.pop_back();
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(t[i]!='#')
                str2.push_back(t[i]);
            else
            {
                if(!str2.empty())
                    str2.pop_back();
            }
        }
        return str1==str2;
    }
};