class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int x=1e9;
        int y=1e9;
        for(auto it : nums1)
            x=min(x,it);
        
        for(auto it : nums2)
            y=min(y,it);
        
        return y-x;
    }
};