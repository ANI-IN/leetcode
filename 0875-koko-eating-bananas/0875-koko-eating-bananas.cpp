class Solution {
    long long solve(vector<int>p, int t, int n)
    {
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+ceil((double)p[i]/(double)t);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n=piles.size();
        long long high=*max_element(piles.begin(),piles.end());
        long long low=1;
        
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long t=solve(piles,mid,n);
            
            if(t<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};