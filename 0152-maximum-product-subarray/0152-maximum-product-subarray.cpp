class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            int temp_max = max_product * nums[i];
            int temp_min = min_product * nums[i];
            
            max_product = max({nums[i], temp_max, temp_min});
            min_product = min({nums[i], temp_max, temp_min});
            
            result = max(result, max_product);
        }
        
        return result;
    }
};