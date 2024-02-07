class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto it : s)
        {
            m[it]++;
        }
        
        priority_queue<pair<int,char>> q;
        
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