class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string temp="";
        int len=1e9;
        
        for(int i=0;i<n;i++)
        {
            if(strs[i].size()<len)
            {
                temp=strs[i];
                len=temp.size();
            }
        }
        
        
        int count=0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=temp[i])
                    return temp.substr(0,count);
            }
            count++;
        }
        
        return temp.substr(0,count);
    }
};