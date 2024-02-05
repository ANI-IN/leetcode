class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int sum=0,i=0,j=n-1;
        
        
        for(i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        
        int maxi=sum;
        
        i=k-1;
        
        while(i>=0 && j>=0)
        {
            sum=sum-arr[i];
            sum=sum+arr[j];
            i--;
            j--;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};