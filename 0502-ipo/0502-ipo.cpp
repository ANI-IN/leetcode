class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>>pq;//pair<profit,capital>
        for(int i=0;i<profits.size();i++)
        {
            pq.push({profits[i],capital[i]});
        }
        vector<pair<int,int>>temp;
        while(k--)
        {
            while(!pq.empty() && w<pq.top().second)
            {
                temp.push_back(pq.top());
                pq.pop();
            }
            if(pq.empty())
            return w;
            w+=pq.top().first;
            pq.pop();
            for(auto it:temp)
            pq.push(it);
            temp.clear();
        }
        return w;
    }
};