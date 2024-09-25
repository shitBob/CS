#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // 对孩子的贪心因子进行排序
        std::sort(g.begin(), g.end());
        // 对饼干的大小进行排序
        std::sort(s.begin(), s.end());

        int childIndex = 0;  // 孩子的索引
        int cookieIndex = 0; // 饼干的索引

        // 当孩子或饼干用完时停止迭代
        while (childIndex < g.size() && cookieIndex < s.size()) {
            // 如果当前的饼干可以满足当前孩子的贪心
            if (s[cookieIndex] >= g[childIndex]) {
                // 移动到下一个孩子，因为这个孩子已经满足
                childIndex++;
            }
            // 不论是否满足，都移动到下一个饼干
            cookieIndex++;
        }

        // 满意的孩子数量就是最终的 childIndex 值
        return childIndex;
    }
};