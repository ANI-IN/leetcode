class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it : nums)
            st.insert(it);
        
        if(st.size()==nums.size())
            return false;
        else
            return true;
    }
};