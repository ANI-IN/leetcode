class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,n=s.size();
        int ans=0,maxi=0;
        unordered_map<char,int>m;
      
        while(j<n)
        {   
            
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);
            int len=j-i+1;
            if(len-maxi>k)
            {
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};