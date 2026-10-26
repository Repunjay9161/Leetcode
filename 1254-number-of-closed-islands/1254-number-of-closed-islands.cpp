class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m =grid[0].size();
       int c=0;
       vector<vector<bool>>visit(n,vector<bool>(m,false));
       for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==0&&!visit[i][j]){
             if(i+1==n||i-1==-1||j+1==m||j-1==-1){
            dfs(i,j,visit,grid,n,m);
           }
           }
        }
       } 
        for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
        if(grid[i][j]==0&&!visit[i][j]){
           dfs(i,j,visit,grid,n,m);
           c++; 
        }
        }
       }
       return c;
    }
    private: 
    void dfs(int i,int j,vector<vector<bool>>&visit, vector<vector<int>>& grid,int n,int m){
        if(i>=n||j>=m||i<0||j<0||grid[i][j]==1||visit[i][j]){
            return;
        }
        visit[i][j] =true;
      dfs(i+1,j,visit,grid,n,m);
      dfs(i,j-1,visit,grid,n,m);
      dfs(i-1,j,visit,grid,n,m);
      dfs(i,j+1,visit,grid,n,m);
    }
};