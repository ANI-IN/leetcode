class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }
            j=i;
            while(i<n && s[i]!=' ')
            {
                i++;
            }
            reverse(s.begin()+j,s.begin()+i);
        }
        return s;
        
        
    }
};