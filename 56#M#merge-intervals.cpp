#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // 按照区间起始位置进行排序

    sort(intervals.begin(), intervals.end(), Solution::cmp_sort);

    vector<vector<int>> mergedIntervals;
    for (const vector<int>& interval : intervals) {
        // 如果当前合并区间列表为空，或者当前区间与上一个区间不重叠，则直接加入合并区间列表
        if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
            mergedIntervals.push_back(interval);
        }
        // 如果当前区间与上一个区间重叠，则更新上一个区间的结束位置
        else {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
        }
    }

    return mergedIntervals;
}
private:
    static bool cmp_sort(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};



int main() {
     Solution solution;
    vector<vector<int>> intervals = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = solution.merge(intervals);

    cout << "Merged Intervals:" << endl;
    for (const vector<int>& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}


/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。



*/