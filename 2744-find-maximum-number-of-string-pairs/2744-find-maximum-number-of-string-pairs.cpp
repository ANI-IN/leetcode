class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        
        int n=words.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            for(int j=i+1;j<n;j++)
            {
                string str1=words[j];
                reverse(str1.begin(),str1.end());
                if(str==str1)
                    c++;
            }
        }
        return c;
    }
};