class Solution {
    int solve(vector<int> arr, int w)
    {
        int n=arr.size();
        int ans=0;
        int days=1;
        for(int i=0;i<n;i++)
        {
            if(ans+arr[i]<=w)
            {
                ans+=arr[i];
            }
            else
            {
                days++;
                ans=arr[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=0;
        for(auto it : arr)
            high+=it;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ans=solve(arr,mid);
            
            if(ans<=days)
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