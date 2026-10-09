class Solution {
private:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& visit, int n) {
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            // Traverse all unvisited connected neighbors
            if (isConnected[u][v] == 1 && !visit[v]) {
                dfs(v, isConnected, visit, n);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n, false);
        int provinces = 0;

        // Outer loop ensures every disconnected graph component is visited
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                provinces++; // Found a new province
                dfs(i, isConnected, visit, n);
            }
        }

        return provinces;
    }
};