class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size(); // 当前层节点数量
            for(int i = 0; i < levelSize; i++){
                TreeNode* cur = q.front();
                q.pop();
                // 当前层最后一个，就是右视图节点
                if(i == levelSize - 1){
                    res.push_back(cur->val);
                }
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};
