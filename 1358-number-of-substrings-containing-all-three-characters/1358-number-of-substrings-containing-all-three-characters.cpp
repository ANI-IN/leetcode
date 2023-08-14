class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int>m;
        int c=0;
        
        while(j<n)
        {
            m[s[j]]++;
            
            while(m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                c+=(n-j);
                m[s[i]]--;
                
                i++;
            }
            j++;
        }
        return c;
    }
};