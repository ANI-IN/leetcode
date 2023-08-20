class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int threshold = n / 4;
        int count = 0;
        int prev = -1;
        
        for (int i = 0; i < n; i++) {   
            if (count > threshold) {
                return prev;
            }
            
            if (arr[i] != prev) {
                count = 1;
                prev = arr[i];
            } else if (arr[i] == prev) {
                count++;
            }
        }
        
        // Check count one more time before returning
        if (count > threshold) {
            return prev;
        }
        
        return 0; // No special integer found
    }
};
