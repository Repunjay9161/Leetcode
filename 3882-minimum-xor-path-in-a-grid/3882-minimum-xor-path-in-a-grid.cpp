class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
      int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<std::bitset<1024>>> dp(n, std::vector<std::bitset<1024>>(m));
        
        dp[0][0].set(grid[0][0]);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If this cell cannot be reached, skip
                if (dp[i][j].none()) continue;
                
                // Move right
                if (j + 1 < m) {
    
                    int next_val = grid[i][j + 1];
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i][j + 1].set(x ^ next_val);
                        }
                    }
                }
                
                // Move down
                if (i + 1 < n) {
                    int next_val = grid[i + 1][j];
                    for (int x = 0; x < 1024; ++x) {
                        if (dp[i][j].test(x)) {
                            dp[i + 1][j].set(x ^ next_val);
                        }
                    }
                }
            }
        }
        
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1][m - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};