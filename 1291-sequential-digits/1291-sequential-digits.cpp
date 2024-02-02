class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
         q.push(1);
         q.push(2);
         q.push(3);
         q.push(4);
         q.push(5);
         q.push(6);
         q.push(7);
         q.push(8);
        vector<int> ans;
        
        while(!q.empty())
        {
            int no=q.front();
            q.pop();
            
            if(no>=low && no<=high)
            {
                ans.push_back(no);
            }
            
            int last=no%10;
            if(last+1<=9)
            {
                q.push(no*10+last+1);
            }
        }
        return ans;
    }
};