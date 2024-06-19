class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.size();
        
        unordered_map<char,int> m;
        
        int start=0,ans=INT_MAX;
        
        string str="";
        
        for(auto it : t)
            m[it]++;
        
        int count=m.size();
        
        
        while(j<n)
        {
            m[s[j]]--;
            
            if(m[s[j]]==0)
            count--;
            if(count==0)
            {
                while(count==0)
                {
                    if(ans>j-i+1)           // ans=min(ans,j-i+1);
                    {
                        ans=j-i+1;
                        start=i;
                    }
                    
                    m[s[i]]++;
                    if(m[s[i]]>0)
                        count++;
                    
                    i++;
                }
            }
            j++;
            
        }
        
        if(ans==INT_MAX)
            return "";
        else
            return s.substr(start,ans);
    }
};