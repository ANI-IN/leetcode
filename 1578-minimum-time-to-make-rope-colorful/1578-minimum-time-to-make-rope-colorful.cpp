class Solution {
public:
    int minCost(string color, vector<int>& Time) {
        int n=color.size();
        
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(color[i]==color[i+1])
            {
                if(Time[i]<Time[i+1])
                {
                    ans+=Time[i];
                }
                else
                {
                    ans+=Time[i+1];
                    Time[i+1]=Time[i];
                }
            }
        }
        return ans;
            
    }
};