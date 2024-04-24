class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        
        for(auto it : num)
        {
            while(!ans.empty() && ans.back()>it && k)
            {
                k--;
                ans.pop_back();
            }
            if(it!='0' || ans.size() )
                ans.push_back(it);
        }
        
        
        while(!ans.empty() && k)
        {
            k--;
            ans.pop_back();
        }
        
        if(ans.empty())
            return "0";
        else
            return ans;
        
    }
};