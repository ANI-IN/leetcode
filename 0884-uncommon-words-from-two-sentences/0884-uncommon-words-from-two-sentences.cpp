class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        vector<string> ans;
        stringstream ss(s1);
        string token=" ";
        
        while(ss >> token)
        {
            m[token]++;
        }
        
        
        stringstream sss(s2);
        while(sss >> token)
        {
            m[token]++;
        }
        for(auto it : m)
        {
            if(it.second==1)
                ans.push_back(it.first);
        }
        return ans;
        
    }
};