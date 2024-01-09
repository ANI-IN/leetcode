class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str="";
        string token="";
        
        
        while(ss >> token)
        {
            str=token+" "+str;
        }
        
        return str.substr(0,str.size()-1);
    
    
    }
};