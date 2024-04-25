class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0;
        int i=0,j=n-1;
        
        for(i=0;i<k;i++)
            sum+=arr[i];
        
        int ans=0;
        ans=sum;
        i=k-1;
        while(j>=0 && i>=0)
        {
            sum=sum-arr[i];
            
            sum=sum+arr[j];
            i--;
            j--;
            
            ans=max(ans,sum);
        }
        return ans;
    }
};