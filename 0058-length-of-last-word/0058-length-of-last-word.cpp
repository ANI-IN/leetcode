class Solution {
public:
    int lengthOfLastWord(string s) {
     int ans=0;
        int n=s.size();
        
        int flag=1;
        for(int i=n-1;i>=0;i--)
        {
            if(flag==1 && s[i]==' ')
                continue;
            else if(s[i]!=' ')
            {
                flag=0;
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};