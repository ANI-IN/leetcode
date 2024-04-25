class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0,ans=0;
        unordered_map<char,int> m;
        
        
        while(j!=s.size())
        {
            m[s[j]]+=1;
            while(m['a'] && m['b'] && m['c'])
            {
                ans+=(n-j);
                
                m[s[i]]-=1;
                
                i++;
            }
            j++;
        }
        return ans;
    }
};