class Solution {
public:
    int countOrders(int n) {
        int odd=3, mod=1e9+7;
        long long ans=1;
        for(int i=2; i<=n; i++)
        {
            int sum = (odd)*(odd+1)%mod/2;
            ans=ans*sum%mod;
            odd+=2;
        }
        return ans%mod; 
    }
};