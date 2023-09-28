class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        unordered_map<int,int>m;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int rem=target-nums[i];
            if(m.find(rem)!=m.end())
            {
                int index=m[rem];
                ans.push_back({i});
                ans.push_back({index});
                break;
            }
            m[nums[i]]=i;
        }
        return ans;
            
    }
};