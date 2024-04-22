class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        string start="0000";
        unordered_set<string> st(begin(deadends),end(deadends));
        
        if(st.count(start))
        {
            return -1;
        }
        
        int level=0;
        queue<string> q;
        q.push(start);
        
        
        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                string str=q.front();
                q.pop();
                
                if(str==target)
                    return level;
                
                for(int k=0;k<4;k++)
                {
                    char ch=str[k];
                    char inc=ch=='9'?'0':ch+1;
                    char dec=ch=='0'?'9':ch-1;
                    
                    str[k]=inc;
                    if(st.find(str)==st.end())
                    {
                        q.push(str);
                        st.insert(str);
                    }
                    
                    str[k]=dec;
                    if(st.find(str)==st.end())
                    {
                        q.push(str);
                        st.insert(str);
                    }   
                    str[k]=ch;                
                }
            }
            level++;
        }
        return -1;
    }
};