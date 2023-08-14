class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        
        int sum=0;
        
        for(int i=0;i<k;i++)
            sum+=arr[i];
        
        int i=k-1,j=n-1;
        int maxi=-1e9;
        
        while(i>=0    )
        {   
            cout<<arr[i]<<" "<<arr[j];
            maxi=max(maxi,sum);
            sum=sum-arr[i];
            sum=sum+arr[j];
            i--;
            j--;
            maxi=max(maxi,sum);
        }
        return maxi;
        
        
        return 0;
        
    }
};