class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int len=INT_MAX;
        
        string temp="";
        
        for(int i=0;i<n;i++)
        {
            if(len>strs[i].size())
            {
                len=strs[i].size();
                temp=strs[i];
            }
        }
        int count=0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=temp[i])
                {
                    return temp.substr(0,count);
                }
            }
            count++;
        }
        
        return temp.substr(0,count);
    }
};