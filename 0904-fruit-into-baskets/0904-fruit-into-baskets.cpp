class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0,j=0,ans=0;
        unordered_map<int,int>m;
        
        while(j<n)
        {
            m[fruits[j]]++;
            
            if(m.size()<=2)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else if(m.size()>2)
            {
                while(m.size()>2)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0)
                        m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
          
        }
        return ans;
    }
};