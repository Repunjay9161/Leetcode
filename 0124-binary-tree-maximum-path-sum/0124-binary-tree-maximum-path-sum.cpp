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
    int maxPathSum(TreeNode* root) {
       if (!root) return 0;

        int globalMaxSum = INT_MIN;
        unordered_map<TreeNode*, int> nodeGain;
        stack<TreeNode*> s;
        TreeNode* lastVisited = nullptr;
        TreeNode* curr = root;

        while (!s.empty() || curr != nullptr) {
            if (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peekNode = s.top();
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } else {
                    s.pop();
                    
                    int leftGain = (peekNode->left && nodeGain[peekNode->left] > 0) ? nodeGain[peekNode->left] : 0;
                    int rightGain = (peekNode->right && nodeGain[peekNode->right] > 0) ? nodeGain[peekNode->right] : 0;
                    
                    int currentPathSum = peekNode->val + leftGain + rightGain;
                    globalMaxSum = std::max(globalMaxSum, currentPathSum);
                    
                    nodeGain[peekNode] = peekNode->val + std::max(leftGain, rightGain);
                    
                    lastVisited = peekNode;
                }
            }
        }

        return globalMaxSum; 
    }
};