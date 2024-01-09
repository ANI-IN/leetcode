class Solution {
    bool solve(vector<int>w, int d, int m)
    {
        int days=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(sum+w[i]<=m)
            {
                sum=sum+w[i];
            }
            else
            {
                sum=w[i];
                days++;
            }
        }
        if(days<=d)
            return true;
        else
            return false;
    }
public:
    int shipWithinDays(vector<int>& w, int days) {
        int sum=0;
        int low=*max_element(w.begin(),w.end());
        for(auto it : w)
            sum=sum+it;
        int high=sum;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(solve(w,days,mid))
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