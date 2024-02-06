class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();
        unordered_map<string,vector<string>> m;
        
        for(auto it : strs)
        {
            string t=it;
            sort(t.begin(),t.end());
            m[t].push_back(it);
        }
        
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};