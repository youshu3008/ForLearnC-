#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size()){
            return "";
        }
            
    }
};



int main() {
    Solution solution;
    
    // 测试一些例子
    cout << solution.longestCommonPrefix("strs = ["flower","flow","flight"]") << endl;  // 输出: "fl"
    cout << solution.longestCommonPrefix("strs = ["dog","racecar","car"]") << endl; // 输出: 输入不存在公共前缀。
    system("pause");
    return 0;
}
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 仅由小写英文字母组成

*/