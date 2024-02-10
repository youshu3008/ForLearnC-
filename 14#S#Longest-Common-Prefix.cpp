#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(!strs.size()){
        return "";
      };
      int len = strs.size();
      string Prefix = strs[0];
      for (int i = 1; i < len; ++i)
      {
        Prefix = longestCommonPrefix(Prefix,strs[i]);
        if (!Prefix.size()) {
                break;
            };
      };
      return Prefix;
    };
    string longestCommonPrefix(string &str1,string &str2){
    int lens = min(str1.size(),str2.size());
    string Prefixs = "";
    for(int i=0;i<lens;++i){
        if(str1[i]==str2[i]){
            Prefixs = str1.substr(0,i+1);
        }
        else{
            break;
        }
    };
    return Prefixs;
    };
};

int main() {
    Solution solution;

    // 创建字符串向量
    vector<string> input1 = {"cir","car"};
    vector<string> input2 = {"flower", "aflower", "afyflow"};

    // 测试示例
    cout << solution.longestCommonPrefix(input1) << endl;  // Output: "fl"
    cout << solution.longestCommonPrefix(input2) << endl;  // Output: ""

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