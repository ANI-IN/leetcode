class Solution {
public:
    string convertToTitle(int n) {
       int nn=26;
        string s="";
        
        while(n)
        {
            n--;
            int rem=n%26;
            char c=rem+'A';
            s=c+s;
            n=n/26;
        }
        return s;
        
    }
};