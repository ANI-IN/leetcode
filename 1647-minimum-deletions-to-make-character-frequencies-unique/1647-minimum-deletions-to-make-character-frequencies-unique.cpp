class Solution {
public:
    int minDeletions(string s) {
        vector<int> arr(26,0);
        
        for(char c : s)
        {
            arr[c-'a']++;
        }
        int ans=0;
        set<int> st;
        for(int i=0;i<26;i++)
        {
            int f=arr[i];
            if(st.find(f)==st.end())
            {
                st.insert(f);
            }
            else
            {
                while(f>0 && st.count(f))
                {
                    ans++;
                    f--;
                }
                if(f>0)
                    st.insert(f);
            }
        }
        return ans;
    }
};