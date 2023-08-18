class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        
        unordered_map<int,int>m;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it : hand)
            m[it]++;
        for(auto it : m)
            pq.push(it.first);
        
        while(!pq.empty())
        {
            int val=pq.top();
            for(int i=0;i<groupSize;i++)
            {
                if(m.find(val+i)==m.end())
                    return false;
                
                m[val+i]--;
                
                if(m[val+i]==0)
                {
                    if(pq.top()!=val+i)
                        return false;
                    pq.pop();
                }
            }
        }
        return true;
        
        
        
    }
};