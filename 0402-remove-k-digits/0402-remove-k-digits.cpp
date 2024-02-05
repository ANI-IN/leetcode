class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        
        for(auto it : num)
        {
            
            while(!ans.empty() && k && ans.back()>it)
            {
                ans.pop_back();
                k--;
            }
            if(it!='0' || ans.size())
                ans.push_back(it);
            
        }
        
        while(ans.size() && k)
        {
            ans.pop_back();
            k--;
        }
        if(ans=="")
            return "0";
        else
            return ans;
    }
};