class Solution {
    double calculateSum(vector<int>& nums, int divisor) {
        double sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / divisor);
        }
        return sum;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            double currentSum = calculateSum(nums, mid);
            
            if (currentSum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};