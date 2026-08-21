#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // 第一步：遍历，腐烂橘子入队，统计新鲜橘子数量
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        // 没有新鲜橘子，直接返回0
        if(fresh == 0) return 0;

        // 上下左右偏移量
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int time = 0;

        // BFS 层序遍历，一层 = 1分钟
        while(!q.empty()){
            int sz = q.size();
            // 处理当前这一层所有腐烂橘子
            for(int k = 0; k < sz; k++){
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;

                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    // 在边界内，并且是新鲜橘子
                    if(nx >=0 && nx < m && ny >=0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2; //腐烂
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            time++; //这一层扩散完成，时间+1
        }
        // 还有新鲜橘子没烂完
        if(fresh > 0) return -1;
        return time - 1;
    }
};

