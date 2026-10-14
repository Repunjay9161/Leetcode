class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m =board[0].size();
         vector<vector<bool>>visit(n, vector<bool>(m ,false));
          for(int i =0; i<n;i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O'&&!visit[i][j]){
                if(i+1==n||i-1==-1||j-1==-1||j+1==m){
                dfs(i,j,board,visit,n,m);
                }
            }
        }
       }
          for(int i =0; i<n;i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O'&&!visit[i][j]){
                board[i][j]='X';
            }
        }
          }
    }
    private:
     void dfs(int i ,int j ,vector<vector<char>> &board,vector<vector<bool>> &visit,int n ,int m){
        if(i>=n||j>=m||i<0||j<0||board[i][j]=='X'||visit[i][j]){
        
            return;
        } 
      visit[i][j]=true;
       dfs(i+1,j,board,visit,n,m);
       dfs(i,j-1,board,visit,n,m);
       dfs(i-1,j,board,visit,n,m);
       dfs(i,j+1,board,visit,n,m);
    }
};