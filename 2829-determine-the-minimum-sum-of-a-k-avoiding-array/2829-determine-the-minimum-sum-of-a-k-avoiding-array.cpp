class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int i=1;
        int sum=0;
        while(n)
        {
            if(st.find(i)==st.end())
            {
                sum=sum+i;
                
                st.insert(k-i);
                n--;
            }
            i++;
            
            
        }
        return sum;
    }
};