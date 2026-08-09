class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;

        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while(top <= bottom && left <= right)
        {
            // 1. 左到右，顶行
            for(int j = left; j <= right; j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            if(top > bottom) break;

            // 2. 上到下，右列
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left > right) break;

            // 3. 右到左，底行
            for(int j = right; j >= left; j--){
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
            if(top > bottom) break;

            //4. 下到上，左列
            for(int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
