class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n);
        vector<int> suff(n);
        
        pre[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            pre[i]=max(pre[i-1],arr[i]);
        }
        
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=max(suff[i+1],arr[i]);
        }
        
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(pre[i],suff[i])-arr[i];
        }
        return ans;
            
            
            return 0;
    }
};