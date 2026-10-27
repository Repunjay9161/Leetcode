class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> grid(m, string(n, '#'));
        
        // 1. Fill the first row completely with free cells ('.')
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};