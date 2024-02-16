class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(auto it : arr)
            m[it]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;    // frequency value
        
        for(auto it : m)
        {
            int val=it.first;
            int freq=it.second;
            
            q.push({freq,val});
        }
        
        while(k>0 && !q.empty())
        {
            auto it=q.top();
            q.pop();
            
            int val=it.second;
            int freq=it.first;
            
            if(k>=freq)
            {
                k=k-freq;
            }
            else
            {
                q.push({freq-k,val});
                k=0;
            }
            
        }
        return q.size();
    }
};