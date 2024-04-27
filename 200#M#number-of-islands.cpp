#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class SolutionBFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // 定义方向数组，用于探索四个方向
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // 使用队列来实现 BFS
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count; // 发现一个岛屿
                    
                    // 将当前岛屿标记为已访问
                    grid[i][j] = '0';
                    
                    // 将当前位置加入队列
                    q.push({i, j});
                    
                    // 进行 BFS
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        // 探索当前位置的四个方向
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            
                            // 检查边界和是否为陆地
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
                                // 标记当前位置为已访问
                                grid[nx][ny] = '0';
                                // 将当前位置加入队列，继续探索
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};

class Solution {
public:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 边界条件和是否为陆地的判断
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // 将当前陆地标记为已访问
        grid[i][j] = '0';
        
        // 递归探索当前陆地的四个方向
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
    
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // 遍历整个网格
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 发现一个岛屿
                if (grid[i][j] == '1') {
                    ++count;
                    // 对当前岛屿进行深度优先搜索
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    
    Solution sol;
    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    
    return 0;
}
