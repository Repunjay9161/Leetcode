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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return NULL;
        if(root->val==key){
            return connect(root);
        }
        TreeNode* curr =root;
        while(root!=nullptr){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = connect(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right&& root->right->val==key){
                    root->right = connect(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        } 
        return curr; 
    }
     TreeNode* connect(TreeNode* root){
        if(root->left==nullptr) return root->right;
        if(root->right == nullptr)return root->left;
        TreeNode* rightPart = root->right;
        TreeNode* last_left = find(root->left);
           last_left->right=rightPart;
           return root->left;
     }
     TreeNode* find(TreeNode* root){
        if(root->right==nullptr) return root;
       return find(root->right);
     }
};