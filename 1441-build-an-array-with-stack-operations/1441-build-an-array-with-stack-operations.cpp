class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string pu="Push";
        string po="Pop";
        int len=target.size();
        
        int i=0,stream=1;
        vector<string> ans;
        
        while(i<len && stream<=n)
        {
              ans.push_back(pu);
            if(stream==target[i])
            {
                i++;
            }
            else
            {
                ans.push_back(po);
            }
            stream++;  
        }
        return ans;
}
};