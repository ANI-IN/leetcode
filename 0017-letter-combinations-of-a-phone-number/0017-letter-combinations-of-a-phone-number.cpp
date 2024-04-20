class Solution {
    void solve(int index, string &str, vector<string>&res,vector<string>&ans, string temp)
    {
        if(index==str.size())
        {
            ans.push_back(temp);
            return;
        }
        
        int digit=(int)str[index]-'0';
        string ss=res[digit];
        
        for(int i=0;i<ss.size();i++)
        {
            temp.push_back(ss[i]);
            solve(index+1,str,res,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
       vector<string> res={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
        
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        
        solve(0,digits,res,ans,"");
        return ans;
            
    }
};