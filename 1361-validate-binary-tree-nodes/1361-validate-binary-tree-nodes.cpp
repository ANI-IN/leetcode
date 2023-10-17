class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        unordered_map<int,int> mp;                  // child -- > parent
        vector<int> adj[n];                         // u -> v
        
        
        for(int i=0;i<n;i++)
        {
            int node=i;
            int leftc=leftChild[i];
            int rightc=rightChild[i];
            
            if(leftc!=-1)
            {
                adj[node].push_back(leftc);
                if(mp.find(leftc)!=mp.end())
                return false;
                else
                mp[leftc]=node;
            }
            
            if(rightc!=-1)
            {   
                adj[node].push_back(rightc);
                if(mp.find(rightc)!=mp.end())
                return false;
                else
                mp[rightc]=node;
            }
        }
        
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                if(root!=-1)
                    return false;
                else
                root=i;
            }
        }
        
        if(root==-1)
            return false;
        
        queue<int> q;
        vector<bool> vis(n,false);
        
        vis[root]=true;
        q.push(root);
        int count=1;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it :  adj[node])
            {
                if(vis[it]==false)
                {   
                    count++;
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        
        return count==n;
        
    
    }
};