class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>q;
        for(auto it : s)
            m[it]++;
        
        for(auto it : m)
            q.push({it.second,it.first});
    
    
    string ans="";
    
    while(q.size()>1)
    {
        auto x=q.top();
        q.pop();
        
        auto y=q.top();
        q.pop();
        
        ans+=x.second;
        ans+=y.second;
        
        x.first--;
        y.first--;
        
        if(x.first>0)
            q.push(x);
        
        if(y.first>0)
            q.push(y);
    }
    
    if(!q.empty())
    {
        if(q.top().first>1)
            return "";
        else
            ans+=q.top().second;
    }
    return ans;
}
};