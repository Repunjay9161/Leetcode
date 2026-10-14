class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
   int n = mat.size();
        int m = mat[0].size();
        
        // Distance matrix initialized with -1 (or a large number) to track unvisited cells
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Push all 0s into the queue and set their distance to 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Direction vectors for moving Up, Right, Down, Left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        // Step 2: Process the queue (Multi-Source BFS)
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // Check if the neighbor is valid and hasn't been visited yet
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && dist[nrow][ncol] == -1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return dist;

    }
};