class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        if (dead.count(start)) {
            return -1;
        }
        
        int level = 0;
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();
                
                if (current == target) {
                    return level;
                }
                
                for (int j = 0; j < 4; ++j) {
                    char original = current[j];
                    // Try rotating wheel 'j' up
                    current[j] = (current[j] == '9') ? '0' : current[j] + 1;
                    if (!visited.count(current) && !dead.count(current)) {
                        q.push(current);
                        visited.insert(current);
                    }
                    
                    // Try rotating wheel 'j' down
                    current[j] = (original == '0') ? '9' : original - 1;
                    if (!visited.count(current) && !dead.count(current)) {
                        q.push(current);
                        visited.insert(current);
                    }
                    
                    // Restore current to original state
                    current[j] = original;
                }
            }
            
            ++level;
        }
        
        return -1;
    }
};
