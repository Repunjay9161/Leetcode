class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visit, vector<int>& ans) {
        visit[node] = 1; // 1 means currently visiting (recursion stack)
        
        for (int neighbor : adj[node]) {
            if (visit[neighbor] == 1) return true; // Cycle detected
            if (visit[neighbor] == 0) {
                if (dfs(neighbor, adj, visit, ans)) return true;
            }
        }
        
        visit[node] = 2; // 2 means fully visited
        ans.push_back(node); // Add to post-order
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build adjacency list
        // Note: prerequisites[i] = [ai, bi] means bi -> ai
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int> ans;
        vector<int> visit(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        
        // 2. Run DFS for all components
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0) {
                if (dfs(i, adj, visit, ans)) {
                    return {}; // Return empty array if cycle exists
                }
            }
        }
        
        // 3. Since DFS post-order gives reverse topological order, reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};