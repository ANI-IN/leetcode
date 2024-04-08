class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        
        queue<int> q;
        int n=sandwiches.size();
        
        for(auto it : students)
            q.push(it);
        
        int i=0,rotation=0;
        
        
        while(!q.empty() && rotation<q.size())
        {
            if(q.front()==sandwiches[i])
            {
                q.pop();
                i++;
                rotation=0;
            }
            else
            {
                int c=q.front();
                q.pop();
                q.push(c);
                rotation++;
            }
        }
        return q.size();
    }
};