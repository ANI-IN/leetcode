class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
       int x = cost[0];
       int y = cost[1];
        
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            int current=cost[i]+min(x,y);
            x=y;
            y=current;
        }
        
        return min(x,y);   
    }
};