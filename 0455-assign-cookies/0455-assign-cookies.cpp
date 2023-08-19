class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int len_g=g.size();
        int len_s=s.size();
        int i=0,j=0,c=0;
        
        while(i<len_g && j<len_s)
        {
            if(s[j]>=g[i])
            {
                i++;
                c++;
            }
            j++;
        }
        return c;
    }
};