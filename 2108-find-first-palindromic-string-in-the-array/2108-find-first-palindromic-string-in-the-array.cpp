class Solution {
    bool solve(string str)
    {
        int start = 0, end = str.size()-1;

    while (start < end)
    {
        if (str[start] != str[end]) // Compare characters at start and end positions
            return false;

        start++;
        end--;
    }
    return true; // Return true if the string is a palindrome
        
    }
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        
        for(int i=0;i<n;i++)
        {
            if(solve(words[i]))
                return words[i];
        }
        return "";
    }
};