class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subset=1<<n;        //2 power n
        
        vector<vector<int>> ans;
        
        for(int i=0;i<subset;i++)
        {
            vector<int> temp;
            
            for(int k=0;k<n;k++)
            {
                if(i & (1<<k))
                {
                    temp.push_back(nums[k]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};