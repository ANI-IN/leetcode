class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<0 && st.top()>0)
            {
                int sum=st.top()+arr[i];
                
                if(sum<0)
                {
                     st.pop();
                }
                else if(sum==0)
                {
                    st.pop();
                    arr[i]=0;
                    break;
                }
                else
                {
                   arr[i]=0;
                    break;
                }
            }
            if(arr[i]!=0)
                st.push(arr[i]);
        }
        
        int s=st.size();

        vector<int> ans(s);
        int i=s-1;
        while(!st.empty())
        {
            ans[i]=st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};