class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
      int m=grid[0].size();
       int ans = 0;
       vector<vector<bool>> visit(n,vector<bool>(m,false));
       queue<pair<pair<int,int>,int>> q;
       for(int i =0;i<n;i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i , j}, 0});
                visit[i][j]=true;
            }
        }
       }
        while(!q.empty()){
            int  i= q.front().first.first;
            int j=q.front().first.second;
            int time =q.front().second;
            q.pop();
            ans=max(ans,time);
            if(i-1>=0&&grid[i-1][j]==1&&!visit[i-1][j]){
                q.push({{i-1,j}, time+1});
                visit[i-1][j]=true;
            }
             if(j-1>=0&&grid[i][j-1]==1&&!visit[i][j-1]){
                q.push({{i,j-1}, time+1});
                visit[i][j-1]=true;
            }
             if(i+1<n&&grid[i+1][j]==1&&!visit[i+1][j]){
                q.push({{i+1,j}, time+1});
                visit[i+1][j]=true;
            }
             if(j+1<m&&grid[i][j+1]==1&&!visit[i][j+1]){
                q.push({{i,j+1}, time+1});
                visit[i][j+1]=true;
            }

        }
       for(int i =0;i<n;i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1&&!visit[i][j]){
                return -1;
            }
        }
       }
        return ans;
       }
    };