class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> time(n);
        
        for(int i=0;i<n;i++)
        {
            time[i]=ceil((float)dist[i]/speed[i]);
        }
        
        sort(time.begin(),time.end());
        int weapon=1;
        int count=1;
        int time_pass=1;
        for(int i=1;i<n;i++)
        {
            if(time[i]-time_pass<=0)
                return count;
            
            time_pass++;
            count++;
        }
        return count;
    }
};