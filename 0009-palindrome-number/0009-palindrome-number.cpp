class Solution {
public:
    bool isPalindrome(int x) {
        
        string str= to_string(x);
        cout<<str;
        
        int n=str.size();
        int low=0,high=n-1;
        
        while(low<=high)
        {
            if(str[low]!=str[high])
                return false;
            
            low++;
            high--;
        }
        
        return 1;
        
        
    }
};