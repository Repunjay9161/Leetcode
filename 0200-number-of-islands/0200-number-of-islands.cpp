class Solution {
    private:
    void dfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>> &visit,int n ,int m){
        if(i>=n||j>=m||i<0||j<0||visit[i][j]||grid[i][j]=='0'){
            return;
        }
        visit[i][j]=true;
         dfs(i-1,j,grid,visit,n,m);
          dfs(i,j+1,grid,visit,n,m);
           dfs(i+1,j,grid,visit,n,m);
            dfs(i,j-1,grid,visit,n,m);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int n =grid.size();
       int m =grid[0].size();
       int c=0;
       vector<vector<bool>>visit(n, vector<bool>(m ,false));
       for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++){
            if(grid[i][j]=='1'&&!visit[i][j]){
                c++;
                dfs(i,j,grid,visit,n,m);
                // c++;
            }
        }
       }
       return c; 
    }
};