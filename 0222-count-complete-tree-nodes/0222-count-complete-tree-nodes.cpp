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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=0;
       int rh = 0;
        lh=leftHt(root);
        rh=rightHt(root);
       if(lh==rh){
        return pow(2 ,lh) -1;       
        }
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
    int leftHt(TreeNode* node){
        if (node==nullptr) return 0;
        int ht =1+leftHt(node->left) ;
        return ht;
    }
    int rightHt(TreeNode* node){
        if(node==nullptr) return 0;
        int ht = 1+rightHt(node->right);
        return ht;
    }

};