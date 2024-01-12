class Solution {
   
public:
    bool halvesAreAlike(string s) {
        
        int n=s.size();
        int mid=n/2;
        
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+=isvowel(s[i])-isvowel(s[mid+i]);
            
        }
        return !ans;
    }
     bool isvowel(char &c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
};