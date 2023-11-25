class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1;
        unordered_map<char,bool>m2;
        
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c1=s[i];
            char c2=t[i];
            
            if(m1.find(c1)!=m1.end())
            {
                if(m1[c1]!=c2)
                    return false;
            }
            else
            {
                if(m2.find(c2)==m2.end())
                {
                    m1[c1]=c2;
                    m2[c2]=true;
                }
                else
                    return false;
            }
        }
        return true;
        
    }
};