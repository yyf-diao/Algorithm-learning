#include <unordered_map>
using namespace std;

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
    unordered_map<int, int> inPos;

    TreeNode* build(int preL, int preR, int inL, int inR, vector<int>& preorder) {
        if (preL > preR) return nullptr;

        // 当前区间根节点
        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int rootIdx = inPos[rootVal];
        int leftCnt = rootIdx - inL; // 左子树节点数量

        // 递归构造左子树
        root->left = build(preL + 1, preL + leftCnt, inL, rootIdx - 1, preorder);
        // 递归构造右子树
        root->right = build(preL + leftCnt + 1, preR, rootIdx + 1, inR, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inPos.clear();
        for (int i = 0; i < inorder.size(); ++i) {
            inPos[inorder[i]] = i;
        }
        return build(0, preorder.size()-1, 0, inorder.size()-1, preorder);
    }
};

