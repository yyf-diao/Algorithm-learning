#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false;  //第一行是否原本有0
        bool col0 = false;  //第一列是否原本有0

        // 检查第一行
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                row0 = true;
                break;
            }
        }
        // 检查第一列
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col0 = true;
                break;
            }
        }

        // 用第一行第一列做标记（跳过第一行第一列）
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 根据标记置零 i,j从1开始
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        // 处理原本的第一行
        if(row0){
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        // 处理原本的第一列
        if(col0){
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};
