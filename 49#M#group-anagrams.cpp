#include <iostream>
#include <vector>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};


int main() {
    Solution solution;

    // 创建字符串向量
    vector<string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> input2 = {"a"};

    // 测试示例
    cout << solution.groupAnagrams(input1) << endl;  // Output: "[["bat"],["nat","tan"],["ate","eat","tea"]]"
    cout << solution.groupAnagrams(input2) << endl;  // Output: [["a"]]

    system("pause");
    return 0;
}

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
 

提示：

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/