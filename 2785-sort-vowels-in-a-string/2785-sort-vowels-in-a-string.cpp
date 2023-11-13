class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();   
        vector<char> arr;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                arr.push_back(s[i]);
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                arr.push_back(s[i]);
        }
        
        sort(arr.begin(),arr.end());
        
        int j=0;
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                ans.push_back(arr[j++]);
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                ans.push_back(arr[j++]);
            else
                ans.push_back(s[i]);
        }
        
        return ans;
    }
};