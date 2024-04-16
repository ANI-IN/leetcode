class Solution {
    bool possible(vector<int>&arr,int m, int k, int days)
    {
        int n=arr.size();
        double c=0;
        double ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=days)
            {
                c++;
            }
            else
            {
                ans=ans+floor(c/k);
                c=0;    
            }
        }
         ans=ans+floor(c/k);
         return ans>=m;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n=arr.size();
        if((double)m*(double)k>n)
            return -1;
        
        int low=*min_element(arr.begin(),arr.end());
        int high=*max_element(arr.begin(),arr.end());
        
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(arr,m,k,mid))
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