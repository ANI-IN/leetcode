class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        
        priority_queue<pair<int,char>>q;
        
        for(auto it : m)
        {
            q.push({it.second,it.first});
        }
        
        string ans="";
        while(!q.empty())
        {
            int len=q.top().first;
            char c=q.top().second;
            q.pop();
            while(len--)
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};