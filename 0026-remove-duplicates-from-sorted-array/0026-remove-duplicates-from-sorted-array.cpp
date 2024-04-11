class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto it : nums)
            st.insert(it);
        vector<int> ans(st.begin(),st.end());
        nums=ans;
        return nums.size();
        
    }
};