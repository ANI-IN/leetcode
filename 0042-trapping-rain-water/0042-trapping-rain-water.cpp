class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int prefix[n];
        int sufix[n];
        
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            if(prefix[i-1]<arr[i])
            {
                prefix[i]=arr[i];
            }
            else
            {
                prefix[i]=prefix[i-1];
            }
        }
        
        
        sufix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(sufix[i+1] < arr[i])
            {
                sufix[i]=arr[i];
            }
            else
            {
                sufix[i]=sufix[i+1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            ans=ans+min(prefix[i],sufix[i])-arr[i];
        }
        return ans;
        
    }
};