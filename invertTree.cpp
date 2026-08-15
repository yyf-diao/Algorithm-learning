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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;

        // ·­×ª×ó¡¢ÓÒ×ÓÊ÷
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // ½»»»×óÓÒ
        root->left = right;
        root->right = left;

        return root;
    }
};

