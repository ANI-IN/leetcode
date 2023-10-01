class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string ans="";
        string token="";
        
           while(ss >> token && k)
            {
                ans=ans+" "+token;
                k--;
            }
        
        return ans.substr(1,ans.size());
    }
};