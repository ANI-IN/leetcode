class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans;
        priority_queue< pair <double, pair<int,int>> > pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double frac=(double)arr[i]/(double)arr[j];
                pq.push({frac,{arr[i],arr[j]}});
                
                if(pq.size()>k)
                    pq.pop();
            }
        }
        
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};