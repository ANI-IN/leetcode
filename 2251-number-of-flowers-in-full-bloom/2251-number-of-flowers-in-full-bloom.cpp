class Solution {
  
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       vector<int> start;
       vector<int> endd;
        
        int n=flowers.size();
        for(int i=0;i<n;i++)
        {
            int s=flowers[i][0];
            int e=flowers[i][1];
            
            start.push_back(s);
            endd.push_back(e);
        }
        sort(start.begin(),start.end());
        sort(endd.begin(),endd.end());
        
        int m=people.size();
        int x,y;
        
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            int p=people[i];
            x=upper_bound(start.begin(),start.end(),p)-start.begin();
            y=lower_bound(endd.begin(),endd.end(),p)-endd.begin();
            ans[i]=x-y;
        }
        
        return ans;
        
        
    }
};