class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if(n==1) return {0};
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        
        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indegree[i]==1){
                q.push(i);
                indegree[i]--;
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            ans.clear();
            for(int i=0;i<size;++i){
                int curNode = q.front(); q.pop();
                ans.push_back(curNode);
                for(auto &childNode : graph[curNode]){
                    indegree[childNode]--;
                   if(indegree[childNode]==1){
                       q.push(childNode);
                   }
                }
            }
        }
        return ans;
    }
};