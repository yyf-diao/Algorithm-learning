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
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }

    // check(节点，下界，上界)
    bool check(TreeNode* node, long long lower, long long upper){
        if(node == nullptr) return true;
        // 当前节点不在区间内，直接false
        if(node->val <= lower || node->val >= upper){
            return false;
        }
        // 左子树：必须 < node->val；右子树：必须 > node->val
        return check(node->left, lower, node->val) && check(node->right, node->val, upper);
    }
};

