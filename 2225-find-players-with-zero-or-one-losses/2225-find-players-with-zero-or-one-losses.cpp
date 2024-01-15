class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m1;
        map<int,int> m2;
        int n=matches.size();
        
        for(int i=0;i<n;i++)
        {
            int winner=matches[i][0];
            int loser=matches[i][1];
            
            m1[winner]++;
            m2[loser]++;
        }
        
        vector<vector<int>> ans(2);
        
        
        for(auto it :m1)
        {
            if(m2.find(it.first)==m2.end())
            {
                ans[0].push_back(it.first);
            }
            
        }
        
        for(auto it : m2)
        {
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};