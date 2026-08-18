class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur->left != nullptr){
                // 找左子树最右边节点
                TreeNode* pre = cur->left;
                while(pre->right != nullptr){
                    pre = pre->right;
                }
                pre->right = cur->right;

                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};

