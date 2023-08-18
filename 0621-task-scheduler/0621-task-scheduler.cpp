class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        priority_queue<int> q;
        
        for(auto it : tasks)
            m[it]++;
        
        for(auto it : m)
            q.push(it.second);
        
        int res=0;
        while(!q.empty())
        {   
            vector<int> temp;
            int time=0;
            for(int i=0;i<n+1;i++)
            {
                if(!q.empty())
                {
                    temp.push_back(q.top()-1);
                    q.pop();
                    time++;
                }
            }
            
            for(auto it : temp)
            {
                if(it)
                {
                    q.push(it);
                }
            }
            
            if(q.empty())
                res+=time;
            else
                res+=n+1;
        }
        return res;
    }
};