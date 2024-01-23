class Solution {
    void solve(int index, vector<string>&arr,string str, int &len)
    {
        if(!isunique(str))
            return;
        
        if(str.size()>len)
            len=str.size();
        
        for(int i=index;i<arr.size();i++)
        {
            solve(i+1,arr,str+arr[i],len);
        }
    }        
    
    bool isunique(string word)
    {
        set<char> st;
        for(auto it : word)
        {
            if(st.find(it)!=st.end())
                return false;
            
            st.insert(it);
        }
        return true;
    }

public:
    int maxLength(vector<string>& arr) {
        int len{0};
        solve(0,arr,"",len);
        return len;
    }
};