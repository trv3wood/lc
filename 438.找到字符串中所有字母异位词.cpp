/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.58%)
 * Likes:    1951
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.9M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和
 * p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 *
 *
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    map<char, int> need, window;
    for (const char &c : p)
      need[c]++;
    int l = 0, r = 0, valid = 0;
    while (r < s.size()) {
      if (need.count(s[r])) {
        window[s[r]]++;
        if (window[s[r]] == need[s[r]])
          valid++;
      }
      r++;
      if (valid == need.size()) {
        ans.push_back(l);
      }
      while (r - l >= p.size()) {
        if (need.count(s[l])) {
          if (window[s[l]] == need[s[l]])
            valid--;
          window[s[l]]--;
        }
        l++;
      }
    }
    return ans;
  }
};
// @lc code=end
int main() {
  auto f = [&](Solution &so, string s, string p) {
    for (const auto &n : so.findAnagrams(s, p)) {
      std::cout << n << ',';
    }
    std::cout << '\n';
  };
  Solution s;
  f(s, "cbaebabacd", "abc");
}
