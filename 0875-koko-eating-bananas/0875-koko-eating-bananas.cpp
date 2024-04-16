class Solution {
    double possible(vector<int>&piles,int h, int k)
    {
        double ans=0;
        int n=piles.size();
        
        for(int i=0;i<n;i++)
        {
            ans=ans+ceil((double)piles[i]/(double)k);
        }
        
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=0;
        int high=*max_element(piles.begin(),piles.end());
        
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double time=possible(piles,h,mid);
            if(time<=h)
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