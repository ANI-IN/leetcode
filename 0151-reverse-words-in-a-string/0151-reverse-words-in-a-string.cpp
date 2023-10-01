class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token= "";
        
        string ans="";
        while(ss >> token)
        {
            
            ans = token + " " + ans;
        }
        
       return ans.substr(0,ans.size()-1);
       
    }
};