class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> m(26,0);
        int n=s.size();
        int mm=t.size();
        
        if(n!=mm)
            return false;
        
        for(int i=0;i<n;i++)
        {
            m[s[i]-'a']++;
            m[t[i]-'a']--;
        }
        
        for(auto it : m)
        {
            if(it!=0)
                return false;
        }
        return true;
    }
};