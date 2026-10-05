/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markParent(TreeNode* root , unordered_map<TreeNode* ,TreeNode*> &parent , TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n->left){
                parent[n->left] = n;
                q.push(n->left);
            }
            if(n->right){
                parent[n->right] = n;
                q.push(n->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        markParent(root , parent , target);
        unordered_map<TreeNode* , bool > visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int level= 0;
        while(!q.empty()){
          int size = q.size();
          if(level++ == k) break;
          for(int i=0; i<size; i++){
            TreeNode* n =q.front();
            q.pop();
            if(n->left &&  !visited[n->left]){
                q.push(n->left);
                visited[n->left]=true;

            }
            if(n->right && !visited[n->right]){
                q.push(n->right);
                visited[n->right] = true;
            }
            if(parent[n]&&!visited[parent[n]]){
                q.push(parent[n]);
                visited[parent[n]] = true;
            }
          }

        }
       vector<int> result;
       while(!q.empty()){
        TreeNode* n =q.front(); q.pop();
        result.push_back(n->val);
       }
       return result;
   }
};