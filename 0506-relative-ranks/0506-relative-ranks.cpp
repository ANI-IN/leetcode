class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            q.push({score[i],i});
        }
        vector<string> ans(n);
        
        int i=1;
        while(!q.empty())
        {
            int pos=q.top().second;
            if(i==1)
            {
                ans[pos]="Gold Medal";
            }
            else if(i==2)
            {
                ans[pos]="Silver Medal";
            }
            else if(i==3)
            {
                ans[pos]="Bronze Medal";
            }
            else
            {
                ans[pos]=to_string(i);
            }
            i++;
            q.pop();
        }
        return ans;
    }
};