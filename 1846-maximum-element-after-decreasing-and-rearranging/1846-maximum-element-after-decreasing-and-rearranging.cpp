class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        arr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1])<=1)
               continue;
            else
               arr[i]=arr[i-1]+1;
        }
        return arr.back();
    }
};