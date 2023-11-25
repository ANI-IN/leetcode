class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        
        int maxi=0,curr=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                curr++;
            }
            else if(s[i]==')')
            {
                maxi=max(maxi,curr);
                curr--;
            }
        }
        return maxi;
    }
};