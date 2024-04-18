class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> c1;
        unordered_map<char,bool> c2;
        
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            char d=t[i];
            
            if(c1.find(c)!=c1.end())
            {
                if(c1[c]!=d)
                    return false;
            }
            else
            {
                if(c2.find(d)!=c2.end())
                    return false;
                else
                {
                    c1[c]=d;
                    c2[d]=true;
                }
            }
        }
        return true;
    }
};