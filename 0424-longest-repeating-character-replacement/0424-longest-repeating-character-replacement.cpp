class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0,maxi=0,ans=0;
        unordered_map<char,int> m;
        
        
        while(j<n)
        {
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);
            
            if(j-i+1-maxi>k)
            {
                while(j-i+1-maxi>k)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    
                    i++;
                }
            }
            ans=max(ans,j-i+1);
                
            j++;
        }
        return ans;
    }
};