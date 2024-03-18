#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowZero = false, colZero = false;
        // 需要置零的位置记录在首行、首列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                    if (i == 0) rowZero = true;
                    if (j == 0) colZero = true;
                }
            }
        }
        // 对非首行、首列元素置零
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 处理首行、首列
        for (int i = 0; colZero && i < m; i++) matrix[i][0] = 0;
        for (int j = 0; rowZero && j < n; j++) matrix[0][j] = 0;
    }
};

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//        vector<int> rowZero, latZero;
//        int n = matrix.size(), m = matrix[0].size();
//        for(int i = 0; i < n; i++){
//         for(int j =0; j< m; j++){
//             if(matrix[i][j] == 0){
//                 rowZero.push_back(i);
//                 latZero.push_back(j);
//             }
//         }
//        }
//        for (auto it = rowZero.begin(); it != rowZero.end(); it++){
//             for(int i =0, j = *it; i < n; i++){
//                 matrix[i][j] = 0; // 使用赋值运算符将0赋给矩阵元素
//             }
//        }
//        for (auto it = latZero.begin(); it != latZero.end(); it++){
//             for(int i = *it, j = 0; j < m; j++){
//                 matrix[i][j] = 0; // 使用赋值运算符将0赋给矩阵元素
//             }
//        }
//     }
// };


int main() {
     Solution solution;
     vector<vector<int>> intervals = {{1,1,1},{1,0,1},{1,1,1}};
     solution.setZeroes(intervals);

    cout << "Zero Intervals" << endl;
    for (const vector<int>& interval : intervals) {
        for(int num : interval){
             cout <<  num  ;
        }
       
    }
    cout << endl;

    return 0;
}


/*
矩阵置零

 

给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

示例 1：


输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：


输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

提示：

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？



*/