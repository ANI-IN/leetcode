class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        
        map<char,int> m;
        for(auto it : s)
            m[it]++;
        set<int> st;
        int ans=0;
        for(auto it : m)
        {
            if(st.find(it.second)==st.end())
            {
                st.insert(it.second);
            }
            else
            {
                while(it.second>=0 && st.count(it.second))
                {
                    it.second--;
                    ans++;
                }
                if(it.second>0 )
                    st.insert(it.second);
            }
           
        }
         return ans;
        
    }
};