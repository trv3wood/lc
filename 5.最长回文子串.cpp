/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (40.58%)
 * Likes:    8063
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 5.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的 回文 子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
using namespace std;
// @lc code=start
#define DEBUG 0
#if DEBUG
template <typename T> void debug_out(T t) { std::cerr << t; }

template <typename T, typename... Args> void debug_out(T t, Args... args) {
  std::cerr << t << ", ";
  debug_out(args...);
}

// 核心宏定义
#define debug(...)                                                             \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__),           \
      std::cerr << std::endl
#else
#define debug(...)
#endif
class Solution {
public:
  // 动态规划
  // string longestPalindrome(string s) {
  //   int n = s.size();
  //   int pos = 0, max_len = 1;
  //   vector<vector<bool>> dp(n, vector<bool>(n, false));
  //   for (int len = 1; len <= n; len++) {
  //     debug(len);
  //     for (int i = 0; i + len <= n; i++) {
  //       int j = i + len - 1;
  //       if (s[i] == s[j] && (len <= 2 || dp[i+1][j-1])) {
  //         dp[i][j] = true;
  //         debug(i, j, dp[i][j], string_view(s.c_str() + i,  len));
  //         if (len > max_len) {
  //           max_len = len;
  //           pos = i;
  //         }
  //       }
  //     }
  //   }
  //   return s.substr(pos, max_len);
  // }
  // 中心扩散
  string longestPalindrome(string s) {
    int n = s.size();
    int max_len = 1, pos = 0;

    for (int i = 0; i < n; i++) {
      int l = i, r = i;
      while (l >= 0 && r < n) {
        int len = r - i + 1;
        if (len == 1) {
          if (l >= 1 && s[l - 1] == s[r]) {
            --l;
            continue;
          }
          if (r + 1 < n && s[l] == s[r + 1]) {
            ++r;
            continue;
          }
          if (l >= 1 && r + 1 < n && s[l - 1] == s[r + 1]) {
            --l;
            ++r;
            continue;
          }
        } else {
          if (l >= 1 && r + 1 < n && s[l - 1] == s[r + 1]) {
            --l;
            ++r;
            continue;
          }
        }
        break;
      }
      if (r - l + 1 > max_len) {
        pos = l;
        max_len = r - l + 1;
      }
    }
    return s.substr(pos, max_len);
  }
};
// @lc code=end

// 中心扩散 Deepseek 改进版
pair<int, int> expand(const string &s, int l, int r) {
  while (l >= 0 && r < s.size() && s[l] == s[r]) {
    l--;
    r++;
  }
  return {l + 1, r - 1}; // 退出循环时已越界，回退一步
}
string longestPalindrome(string s) {
  int n = s.size();
  int start = 0, max_len = 1;

  for (int i = 0; i < n; i++) {
    // 奇数长度中心
    auto [l1, r1] = expand(s, i, i);
    if (r1 - l1 + 1 > max_len) {
      max_len = r1 - l1 + 1;
      start = l1;
    }
    // 偶数长度中心
    auto [l2, r2] = expand(s, i, i + 1);
    if (r2 - l2 + 1 > max_len) {
      max_len = r2 - l2 + 1;
      start = l2;
    }
  }
  return s.substr(start, max_len);
}

/*
p[i..j] when p[i + 1..max(j-1, i + 1)] and s[i] = s[j]
p({s | s.len <= 1}) = true
*/
int main() {
  Solution s;
  std::cerr << s.longestPalindrome("cbbd") << '\n';
  std::cerr << s.longestPalindrome("a") << '\n';

  std::cerr << s.longestPalindrome("bb") << '\n';
  std::cerr << s.longestPalindrome("abbcccba") << '\n';

  std::cerr << s.longestPalindrome("babad") << '\n';
}