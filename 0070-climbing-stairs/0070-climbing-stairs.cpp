class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
       int prev0=1;
       int prev1=1;
        
        for(int i=2;i<=n;i++)
        {
            int curr=prev0+prev1;
            prev0=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
};