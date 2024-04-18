class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        
        if(n!=m)
            return false;
        
        for(int i=0;i<n;i++)
        {
            int j=0;
            while( goal[j]==s[(i+j)%n] )
                j++;
            
            if(j==n)
                return true;
        }
        return false;
    }
};