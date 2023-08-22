class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        int prev=0;
        
        for(int curr=1;curr<n;curr++)
        {
            if(a[curr][0] < a[prev][1])
            {
                ans++;
                
                if(a[curr][1]<=a[prev][1])
                {
                    prev=curr;
                }
                
            }
            else
            {
                prev=curr;
            }
        }
        return ans;
    }
};