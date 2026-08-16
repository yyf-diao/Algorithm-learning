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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLen = 0;
        getHeight(root, maxLen);
        return maxLen;
    }
    private:
    int getHeight(TreeNode* node, int& maxLen){
        if(!node) return 0;
        int leftH = getHeight(node->left, maxLen);
        int rigthH = getHeight(node->right, maxLen);

        maxLen = max(maxLen, leftH + rigthH);

        return max(leftH, rigthH) + 1;
    }
};
