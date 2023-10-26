class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long> m;
        int n=arr.size();

        m[arr[0]]=1;
        for(int i=1;i<n;i++)
        {   
            m[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && m.find(arr[i]/arr[j])!=m.end())
                {
                    m[arr[i]]+=m[arr[j]]*m[arr[i]/arr[j]];
                }
            }
        }
        int mod=1e9+7;
        long sum=0;
        
        for(auto it : m)
            sum=(sum+it.second)%mod;
        
        return sum;
    }
};