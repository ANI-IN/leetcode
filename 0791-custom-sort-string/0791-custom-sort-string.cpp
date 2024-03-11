class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        
        for(auto it : s)
        {
            m[it]++;
        }
        
        string ans="";
        for(auto it : order)
        {
            char c=it;
            if(m.find(c)!=m.end())
            {
                int count=m[c];
                while(count!=0)
                {
                    ans.push_back(c);
                    count--;
                }
                m.erase(c);
            }
        }
        
        for(auto it : m)
        {
            char c=it.first;
            int count=it.second;
            
            while(count!=0)
            {
                ans.push_back(c);
                count--;
            }
        }
        
        return ans;
       
    }
};