class Solution {
public:
    bool checkValidString(string s) {
        string str="";
        string ast="";
        int n=s.size();
        
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                str.push_back(i);
            }
            else if(s[i]=='*')
            {
                ast.push_back(i);
            }
            else
            {
                if(str.size()>0)
                    str.pop_back();
                else if(ast.size()>0)
                    ast.pop_back();
                else
                    return false;
            }
        }
        
        while(str.size()>0 && ast.size()>0 && ast.back()>str.back() )
        {
            ast.pop_back();
            str.pop_back();
        }
        
        if(str.size()>0)
            return false;
        else
            return true;
        
    }
};