class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(auto it : s)
            m[it]++;
        
        int ans=0;
        for(auto it : t)
        {
            if(m.find(it)!=m.end())
                m[it]--;
            if(m[it]==0)
                m.erase(it);
        }
        
        for(auto it : m)
            ans+=it.second;
        return ans;
    }
};