class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> visit(n, false);
        
        // 1. Loop through all nodes to cover disconnected components
        for(int i = 0; i < n; i++) {
            if(visit[i]) continue;
            
            queue<int> q;
            q.push(i);
            visit[i] = true;
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                
                if(color[curr] == -1){
                    color[curr] = 0;
                }
                
                for(int v : graph[curr]){
                    // 2. If already visited, check for color conflict immediately
                    if(visit[v]) {
                        if(color[curr] == color[v]) {
                            return false;
                        }
                    } 
                    // 3. If not visited, color it with the opposite and push to queue
                    else {
                        visit[v] = true;
                        q.push(v);
                        color[v] = 1 - color[curr]; // Clean toggle instead of if-else
                    }
                }
            }
        }
        return true;
    }
};