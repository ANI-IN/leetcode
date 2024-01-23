class Solution {
    void solve(int index,string &digits,string arr[], vector<string>&ans, string temp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        
        int digit=(int)digits[index]-'0';
        string str=arr[digit];
        
        for(int i=0;i<str.size();i++)
        {
            temp.push_back(str[i]);
            solve(index+1,digits,arr,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        
        
        int index=0;
        
        solve(0,digits,arr,ans,"");
        return ans;
    }
};