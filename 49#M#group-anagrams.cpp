#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {  
public:  
    vector<vector<string>> groupAnagrams(vector<string>& strs) {  
        // 创建一个哈希表来记录每个排序后的字符串及其对应的原始字符串向量  
        unordered_map<string, vector<string>> record;  
          
        // 遍历输入的字符串向量  
        for (int i = 0; i < strs.size(); i++) {  
            // 对当前字符串进行排序，并将其作为哈希表的键  
            string key = strs[i];  
            sort(key.begin(), key.end());  
            // 将原始字符串添加到与排序后的键相关联的向量中  
            record[key].push_back(strs[i]);  
        }  
          
        // 创建一个结果向量来存储分组后的字母异位词  
        vector<vector<string>> ans;  
          
        // 遍历哈希表，并将每个键对应的向量添加到结果向量中  
        for (auto it = record.begin(); it != record.end(); it++) {  
            ans.push_back(it->second); // it->second 是与当前键相关联的向量  
        }  
          
        // 返回结果向量  
        return ans;  
    }  
};


int main() {
     Solution solution;

    // 创建字符串向量
    vector<string> input1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> input2 = {""};
    vector<string> input3 = {"a"};

    // 测试示例
    vector<vector<string>> output1 = solution.groupAnagrams(input1);
    vector<vector<string>> output2 = solution.groupAnagrams(input2);
    vector<vector<string>> output3 = solution.groupAnagrams(input3);

    // 输出结果
    cout << "[";
    for (const auto& group : output1) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    cout << "[";
    for (const auto& group : output2) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    cout << "[";
    for (const auto& group : output3) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;
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