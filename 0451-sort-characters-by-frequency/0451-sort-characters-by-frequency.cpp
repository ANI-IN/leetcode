class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        string ans="";
        
        
        for(auto it : s)
        {
            m[it]++;
        }
        
        for(auto it : m)
        {
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int len=it.first;
            char c=it.second;
            
            while(len--)
            {
                ans.push_back(c);
            }
        }
        return ans;
        
    }
};