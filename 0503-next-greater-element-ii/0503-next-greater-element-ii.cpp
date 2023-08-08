class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        int n=nums2.size();
        
        stack<int> st;
        vector<int> ans;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i%n]>=st.top())
                st.pop();
            
          if(i<n)
            {
                if(st.empty())
               ans.push_back(-1);
            else
               ans.push_back(st.top());
            }
            
            st.push(nums2[i%n]);
        }
        reverse(ans.begin(),ans.end());
        
        
       
        
        return ans;
       
            
            
    }
};