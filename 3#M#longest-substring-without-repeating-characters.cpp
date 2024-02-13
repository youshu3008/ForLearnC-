#include <iostream>
#include <vector>
#include <unordered_map>
// 滑动窗口题
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 创建一个数组储存每个字符上一次出现的位置
        vector<int> pos(128,-1);
        // 定义结果变量 值为0
        int ans = 0;
        // i 是窗口右边界， j 是窗口左边界， 
        for (int i = 0, j = 0; i < s.length(); i++)
        {
            /* code */
            cout << pos[s[i]] + 1 << endl;
            // 更新窗口左边界的值： 左边界的值就是当前左边界和当前字符上一次出现位置的下一个位置的最大值
            j = max(j,pos[s[i]] + 1);
            // 更新答案，当前窗口的长度
            ans = max(ans,i-j+1);
            // 存储当前字符的位置
            pos[s[i]] = i;
        }
        return ans;
        
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         //1. 确定维护变量：存储字符个数的哈希表
//         unordered_map<char,int> m;
//         int max_len=0;
//         //2. 定义滑动窗口的边界，开始滑动窗口
//         int n=s.size();
//         int left=0,right=0;
//         while (right<n)
//         {
//             //3. 合法更新：哈希表存储字符的更新，字符放到哈希表中
//             m[s[right]]++;
//             if (right-left+1==m.size())
//             {
//                 max_len=max(max_len,right-left+1);
//             }
//             //4. 非法更新：窗口的长度小于哈希表的长度
//             //想象一下：哈希表存储每个字符，如果遇到相同的字符则长度不变，但是窗口的长度会变，因此就造成了窗口里有重复的单词，
//             //非法了，需要更新窗口的左边界，必要时删除此字符
//             while (right-left+1>m.size())
//             {
//                 m[s[left]]--;
//                 if (m[s[left]]==0)
//                 {
//                     m.erase(s[left]);
//                 }
//                 left++;
//             }
//             right++;
//         }
//         //5. 返回结果
//         return max_len;
//     }
// };



int main() {
    Solution solution;

    // 创建字符串向量
    string input1 = "abcbacbb"; //abcabcbb
    string input2 = "bbbbb";

    // 测试示例
    cout << solution.lengthOfLongestSubstring(input1) << endl;  // Output: "3"
    cout << solution.lengthOfLongestSubstring(input2) << endl;  // Output: "1"

    system("pause");
    return 0;
}
/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

*/