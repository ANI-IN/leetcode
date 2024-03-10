class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        vector<int> ans;
        for(auto it : nums2)
        {
            if(s.count(it)!=0)
            {
                ans.push_back(it);
                s.erase(it);
            }
        }
        return ans;
    }
};