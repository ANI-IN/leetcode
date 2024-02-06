class Solution {
    string solve(string str)
    {
        vector<int> arr(26,0);
        for(int i=0;i<str.size();i++)
        {
            arr[str[i]-'a']++;
        }
        
        string ans="";
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
                ans+= string(arr[i], i+'a');
        }
        return ans;
            
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> m;
        
        for(auto it : strs)
        {
            string s=solve(it);
            m[s].push_back(it);
        }
        
        vector<vector<string>> ans;
        for(auto it : m)
        {
            ans.push_back(it.second);
            
        }
        return ans;
    }
};