class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
      
        for(int i=1;i<n;i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];
            
            if(result.back()[1] < start)
            {
                result.push_back(intervals[i]);
            }
            else
            {
                result.back()[0]=min(result.back()[0],start);
                result.back()[1]=max(result.back()[1],end);
            }
        }
            
        return result;
        
    }
};