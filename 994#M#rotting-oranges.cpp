#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 定义方向数组，用于探索四个方向
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        queue<pair<int, int>> q;
        
        // 将所有腐烂的橘子的位置加入队列
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool changed = false;
            
            for (int i = 0; i < size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                // 探索当前腐烂橘子的四个方向
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    // 检查边界和是否为新鲜橘子
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        // 标记新鲜橘子为腐烂
                        grid[nx][ny] = 2;
                        // 将新腐烂的橘子位置加入队列
                        q.push({nx, ny});
                        // 标记状态已改变
                        changed = true;
                    }
                }
            }
            
            // 如果本轮有橘子腐烂，则增加分钟数
            if (changed) {
                ++minutes;
            }
        }
        
        // 检查是否还有新鲜橘子，如果有则返回 -1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return minutes;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    
    Solution sol;
    int minutes = sol.orangesRotting(grid);
    cout << "Minutes required: " << minutes << endl;
    
    return 0;
}
