/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       stringstream ss(data);
        string item;
        queue<string> q;
        while (getline(ss, item, ',')) {
            q.push(item);
        }
        auto helper = [&](auto& self) -> TreeNode* {
            if (q.empty()) return nullptr; 
            string val = q.front();
            q.pop();  
            if (val == "#") return nullptr; 
            TreeNode* root = new TreeNode(stoi(val));
            root->left = self(self);
            root->right = self(self);  
            return root;
        };
        return helper(helper); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));