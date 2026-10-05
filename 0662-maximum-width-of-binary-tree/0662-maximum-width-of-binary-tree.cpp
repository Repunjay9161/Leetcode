/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q;
        long long width = 0;
        q.emplace(root , 0);
        while(!q.empty()){
            int size = q.size();
            long long firstId= q.front().second;
            long long lastId=0;
            for(int i =0; i<size; i++){
            TreeNode* n =q.front().first;
            long long id = q.front().second - firstId;
            q.pop();
            if(i==size-1){
                 lastId = id;
            }
            
            if(n->left) q.emplace(n->left , 2*id+1);
            if(n->right) q.emplace(n->right , 2*id+2);
            }
             width = max(width, lastId+1);
        }
        return width;
    }
};