#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //邻接表 graph[b]存放所有b可以指向的课程
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        //构建图，统计入度
        for(auto& edge : prerequisites){
            int a = edge[0];
            int b = edge[1];
            //学a必须先学b：b → a
            graph[b].push_back(a);
            inDegree[a]++; //a的入度+1
        }

        queue<int> q;
        //入度为0全部入队
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cnt++; //成功选一门课

            //遍历cur所有后继课程
            for(int next : graph[cur]){
                inDegree[next]--;
                if(inDegree[next] == 0){
                    q.push(next);
                }
            }
        }
        //取出的节点等于课程总数，无环
        return cnt == numCourses;
    }
};

