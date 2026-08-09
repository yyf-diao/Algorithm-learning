class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        while(x < m && y >= 0){
            int cur = matrix[x][y];
            if(cur == target) return true;
            else if(cur > target) y--;
            else x++;
        }
        return false;
    }
};
