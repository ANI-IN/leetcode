class Solution {
public:
    int minSteps(string s, string t) {
        
        int n=s.size();
        vector<int> arr(26,0);
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            arr[t[i]-'a']--;
        }
        
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
                c+=arr[i];
        }
        return c;
    }
};