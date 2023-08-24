class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st;
        vector<int> ans;
        int c=0;
        int n=A.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.find(A[i])!=st.end())
                c++;
            else
                st.insert(A[i]);
            
            if(st.find(B[i])!=st.end())
                c++;
            else
                st.insert(B[i]);
            ans.push_back(c);
            
        }
        return ans;
    }
};