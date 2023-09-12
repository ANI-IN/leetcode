class Solution {
public:
    int minDeletions(string s) {
       int arr[26]={0};
        for(char c : s)
        {
            arr[c-'a']++;
        }
        int ans=0;
        sort(begin(arr),end(arr));
        
        for(int i=24;i>=0 && arr[i]>=0;i--)
        {
            if(arr[i]>=arr[i+1])
            {
                int prev=arr[i];
                arr[i]=max(0,arr[i+1]-1);
                
                ans+=prev-arr[i];
            }
        }
        return ans;
    }
};