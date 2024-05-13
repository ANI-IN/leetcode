class Solution {
    int solve(int index,vector<int>&arr, vector<int>&dp, int k)
    {
        if(index>=arr.size())
            return 0;
        if(index==arr.size()-1)
            return arr[index];
        
        if(dp[index]!=-1)
            return dp[index];
        
        int pick=arr[index]+solve(index+k,arr,dp,k);
        
        return dp[index]=pick;
    }
    
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,solve(i,arr,dp,k));
        }
        return ans;
        
    }
};