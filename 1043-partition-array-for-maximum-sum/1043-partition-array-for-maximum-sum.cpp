class Solution {
    int solve(int index, int n, int k, vector<int>&arr, vector<int>&dp)
    {
        if(index==n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        
        int len=0,maxi=-1e9;
        int ele=-1e9;
        for(int j=index; j <min(n,index+k);j++)
        {
            len++;
            ele=max(ele,arr[j]);
            int sum=ele*len + solve(j+1,n,k,arr,dp);
            maxi=max(maxi,sum);
        }
        return dp[index]=maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        
       for(int index=n-1;index>=0;index--)
       {
            int len=0,maxi=-1e9;
            int ele=-1e9;
            for(int j=index; j <min(n,index+k);j++)
            {
                len++;
                ele=max(ele,arr[j]);
                int sum=ele*len + dp[j+1];
                maxi=max(maxi,sum);
            }
            dp[index]=maxi;
       }
        return dp[0];
    }
};