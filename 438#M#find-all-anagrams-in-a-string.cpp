#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 维护区间特征 ---> 滑动窗口
        unordered_map<char,int> mp_p,mp_s;
        // 初始化 mp_p，记录字符串 p 中字符的频次
        for(auto t : p) mp_p[t]++;
        int i = 0,j = 0;
        vector<int> res;
        while(j < s.size()){
            char c  = s[j];
            mp_s[c]++;
            // 如果当前字符 c 的频次超过了在字符串 p 中的频次，
            // 则移动滑动窗口的左边界 i，直至 c 的频次满足条件
            while(mp_s[c] > mp_p[c]) {
                mp_s[s[i++]]--;
            }
            // 若当前滑动窗口长度等于字符串 p 的长度，
            // 且当前滑动窗口中的字符频次与字符串 p 中相同，
            // 则说明找到了一个异位词的子串，将起始索引 i 记录下来
            if(j-i+1 == p.size() && mp_p == mp_s) res.push_back(i);
            j++;
        }
        return res;
    }
};



int main() {
    Solution solution;

    // 测试示例
    string input1_s = "cbaebabacd";
    string input1_p = "abc";
    string input2_s = "abab";
    string input2_p = "ab";

    vector<int> output1 = solution.findAnagrams(input1_s, input1_p);
    vector<int> output2 = solution.findAnagrams(input2_s, input2_p);

    // 输出结果
    cout << "[";
    for (const auto &num : output1) {
        cout << num << ",";
    }
    cout << "]" << endl;

    cout << "[";
    for (const auto &num : output2) {
        cout << num << ",";
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}
/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。



示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母

*/