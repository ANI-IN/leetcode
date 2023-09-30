class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        int n=s.size();
        int m=t.size();
        
        if(n!=m)
            return false;
        
        vector<int> arr(26,0);
        for(int i=0;i<n;i++)
        {
            char c1=s[i];
            char c2=t[i];
            arr[c1-'a']++;
            arr[c2-'a']--;
        }
        for(auto it : arr)
            if(it!=0)
                return false;
        return true;
        
       
        
        
    }
};