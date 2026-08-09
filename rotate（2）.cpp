class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 第一步：矩阵转置
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 第二步：每一行整体反转
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
