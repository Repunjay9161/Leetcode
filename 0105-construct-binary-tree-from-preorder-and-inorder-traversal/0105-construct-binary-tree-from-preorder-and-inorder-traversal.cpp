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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        auto helper = [&](auto& self, int inorderStart, int inorderEnd) -> TreeNode* {
            if (inorderStart > inorderEnd) {
                return nullptr;
            }
            int rootValue = preorder[preorderIndex++];
            TreeNode* root = new TreeNode(rootValue);
            int rootInorderIndex = inorderMap[rootValue];
            root->left = self(self, inorderStart, rootInorderIndex - 1);
            root->right = self(self, rootInorderIndex + 1, inorderEnd);
            return root;
        };
        return helper(helper, 0, inorder.size() - 1);
    }
};