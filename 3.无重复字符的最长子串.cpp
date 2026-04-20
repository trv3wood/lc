/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (42.23%)
 * Likes:    11428
 * Dislikes: 0
 * Total Accepted:    4.2M
 * Total Submissions: 9.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab"
 * 也是正确答案。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 *
 *
 */

#include <array>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  // int lengthOfLongestSubstring(string s) {
  //   int count[128]{0};
  //   int ans = 0;
  //   for (int i = 0, j = 0; j < s.size(); j++) {
  //     count[s[j]]++;
  //     while (count[s[i]] > 1) {
  //       count[s[i]]--;
  //       i++;
  //     }
  //     ans = std::max(ans, j - i + 1);
  //   }
  //   return ans;
  // }
  int lengthOfLongestSubstring(string s) {
    std::array<int, 128> pos_map; // 记录字符最后出现的位置
    pos_map.fill(-1);
    int ans = 0;
    for (int i = 0, j = 0; j < s.size(); j++) {
      if (j != pos_map[s[j]] && pos_map[s[j]] >= i) {
        i = pos_map[s[j]] + 1; // 重复时 i 直接跳跃
      }
      pos_map[s[j]] = j;
      ans = std::max(ans, j - i + 1);
    }
    return ans;
  }
};
// @lc code=end
