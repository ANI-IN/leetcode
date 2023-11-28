class Solution {
    int mod=1e9+7;
public:
    int numberOfWays(string str) {
        int n=str.size();
        vector<int> seat;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='S')
            {
                seat.push_back(i);
                c++;
            }
        }
        if(seat.size()%2 || seat.size()==0)
            return 0;
        
        int m=seat.size();
        long long ans=1;
        for(int i=2;i<m;i=i+2)
        {
            ans=(ans*(seat[i]-seat[i-1]))%mod;
        }
        return ans;
        
        
    }
};