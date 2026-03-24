/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (49.04%)
 * Likes:    3550
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.1M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口
 * 子串，使得该子串包含 t
 * 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。
 *
 * 测试用例保证答案唯一。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 O(m + n) 时间内解决此问题的算法吗？
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int target_map[128] = {0};
        int source_map[128] = {0};
        for (char c : t) target_map[c]++;

        int target_types = 0; // t 中有多少种不同的字符
        for (int i = 0; i < 128; i++) if (target_map[i] > 0) target_types++;

        int left = 0, match = 0;
        int min_len = INT_MAX, start = 0; // 记录最小子串的起点和长度

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            source_map[c]++;
            
            // 只有当数量正好相等时，才增加 match，避免重复计算
            if (source_map[c] == target_map[c]) {
                match++;
            }

            // 当窗口满足条件（match 达标），开始收缩左边界
            while (match == target_types) {
                // 更新最小长度
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start = left;
                }

                char d = s[left++];
                // 如果移除的是目标字符，且移除后不满足数量要求了，match 减 1
                if (source_map[d] == target_map[d]) {
                    match--;
                }
                source_map[d]--;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
// @lc code=end

int main() {
  Solution s;
  std::cout << s.minWindow("ADOBECODEBANC", "ABC");
  // s.minWindow("a", "a");
  // s.minWindow("a", "aa");
}