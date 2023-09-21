class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy=INT_MAX;
        int sell=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            buy=min(buy,prices[i]);
            sell=max(sell,prices[i]-buy);
        }
        return sell;
    }
};