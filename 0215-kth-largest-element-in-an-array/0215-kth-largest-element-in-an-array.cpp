class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums)
            pq.push(it);
        
        
        while(k>1)
        {
            cout<<pq.top();
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};