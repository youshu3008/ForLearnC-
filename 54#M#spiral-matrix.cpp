#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans;
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true){
            for(int i = left;i <= right; ++i) ans.push_back(matrix[up][i]); //向右移动直到最右
            //重新设定上边界，若上边界大于下边界，则遍历遍历完成，
            if(++up > down) break;
            for(int i = up;i <= down; ++i) ans.push_back(matrix[i][right]); //向下
            if(--right < left) break;
            for(int i = right; i >= left; --i) ans.push_back(matrix[down][i]); //向左
            if(--down < up) break;
            for(int i = down; i >=up; --i) ans.push_back(matrix[i][left]); //向上
            if(++left > right) break;
        }
        return ans;
        
    }
};


int main() {
     Solution solution;
     vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
     vector<int> output = solution.spiralOrder(input);

    cout << "螺旋矩阵" << endl;
    for (auto  i : output) {
             cout <<  i << " " ;
    }
    cout << endl;

    return 0;
}


/*
螺旋矩阵

 

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

 

示例 1：


输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：


输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/