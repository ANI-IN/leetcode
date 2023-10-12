class Solution {
  
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       
        
        int n=flowers.size();
        vector<int> start(n);
        vector<int> endd(n);
        for(int i=0;i<n;i++)
        {
            int s=flowers[i][0];
            int e=flowers[i][1];
            
            start[i]=s;
            endd[i]=e;
            
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