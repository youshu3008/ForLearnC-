#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        // 构建课程图和入度数组
        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegree[prerequisite[0]];
        }
        
        queue<int> q;
        
        // 将入度为 0 的课程加入队列
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // 记录完成学习的课程数量
        
        // BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ++count;
            
            // 更新与当前课程相连的课程的入度
            for (int next : graph[course]) {
                --indegree[next];
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // 如果完成学习的课程数量等于总课程数量，则可以完成所有课程学习
        return count == numCourses;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    
    Solution sol;
    bool result = sol.canFinish(numCourses, prerequisites);
    
    cout << "Is it possible to finish all courses? \n" << (result ? "Yes" : "No") << endl;
    
    return 0;
}
