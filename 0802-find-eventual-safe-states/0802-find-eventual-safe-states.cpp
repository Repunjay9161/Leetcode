class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<bool> visit(n,false);
        vector<bool> connect(n,false);
        vector<int> ans;
           for(int i =0;i<n ;i++){
            if(!visit[i]){
                dfs(graph,i,visit,connect);
            }
           }
            for(int i =0;i<n;i++){
                if(connect[i]==false){
                    ans.push_back(i);
                }
            } 
            return ans;       
    }
    private:
   bool dfs(vector<vector<int>>& graph,int v,vector<bool> &visit,vector<bool> &connect){
             visit[v]=true;
             connect[v]=true;

          for(int i: graph[v]){
                if(!visit[i]&&dfs(graph,i,visit,connect)){
                     return true;
                }
                else if(connect[i]) return true;
        }
        connect[v]=false;
        return false;
    }
};