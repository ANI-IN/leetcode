class Solution {
public:
    int minimumSum(int n, int k) {
        // Initialize an array 'arr' to store the sequence of integers.
        vector<int> arr = {1};
        
        // Initialize a variable 'i' to start generating integers from 2.
        int i = 2;
        
        // Initialize a boolean variable 't' to track whether the current integer satisfies the condition.
        bool check;
        
        // Loop until the 'arr' contains 'n' elements.
        while (arr.size() < n) {
            // Reset the 't' flag for each iteration.
            check = true;
            
            // Check each integer 'it' in 'arr' to see if the sum of 'it' and 'i' equals 'k'.
            for (auto it : arr) {
                if (it + i == k) {
                    // If the sum matches 'k', set 't' to false and break out of the loop.
                    check = false;
                    break;
                }
            }
            
            // If 't' is true, the current integer 'i' can be added to 'arr'.
            if (check)
                arr.push_back(i);
            
            // Increment the integer 'i' for the next iteration.
            i++;
        }
        
        // Calculate the sum of all integers in 'arr'.
        int sum = 0;
        for (auto it : arr)
            sum += it;
        
        // Return the calculated sum.
        return sum;
    }
};
