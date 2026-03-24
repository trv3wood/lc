#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        for (size_t i = 0, j = s.size() - 1; i < j;) {
            swap(s[i], s[j]);
            i++; j--;
        }
    }
};
// @lc code=end

