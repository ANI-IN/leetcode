class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token="";
        
        string ans="";
        while(ss >> token)
        {
            reverse(token.begin(),token.end());
            ans=ans+" "+token;
        }
        return ans.substr(1,ans.size());
    }
};