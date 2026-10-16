class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int m = image.size();
      int n =image[0].size();
      int u = image[sr][sc];
     vector<vector<bool>>visit(m, vector<bool>(n ,false));
     dfs(sr,sc,image,color,visit,u,n,m); 
     return image;
    }
    private:
    void dfs(int i, int j,vector<vector<int>> &image, int color,vector<vector<bool>> &visit,int u,int n ,int m){
        if(i>=m||j>=n||i<0||j<0||visit[i][j]||image[i][j]!=u){
            return;
        }
           visit[i][j] =true;
           image[i][j]= color;
            dfs(i-1,j,image,color,visit,u,n,m); 
             dfs(i,j+1,image,color,visit,u,n,m); 
              dfs(i+1,j,image,color,visit,u,n,m); 
               dfs(i,j-1,image,color,visit,u,n,m); 

    }
};