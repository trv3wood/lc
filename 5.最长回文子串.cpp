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
#define DEBUG 1
#if DEBUG
template<typename T>
void debug_out(T t) {
    std::cerr << t;
}

template<typename T, typename... Args>
void debug_out(T t, Args... args) {
    std::cerr << t << ", ";
    debug_out(args...);
}

// 核心宏定义
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__), std::cerr << std::endl
#else
#define debug(...)
#endif
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    int pos = 0, max_len = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int len = 1; len <= n; len++) {
      debug(len);
      for (int i = 0; i + len <= n; i++) {
        int j = i + len - 1;
        int l = std::min(i + 1, n - 1);
        int r = std::max(j - 1, l);
        debug(i, j, l, r, dp[l][r]);
        if (s[i] == s[j] && (len <= 2 || dp[i+1][j-1])) {
          dp[i][j] = true;
          debug(i, j, dp[i][j], string_view(s.c_str() + i,  len));
          if (len > max_len) {
            max_len = len;
            pos = i;
          }
        }
      }
    }
    return s.substr(pos, max_len);
  }
};
// @lc code=end

/*
p[i..j] when p[i + 1..max(j-1, i + 1)] and s[i] = s[j]
p({s | s.len <= 1}) = true
*/
int main() {
  Solution s;
  std::cerr << s.longestPalindrome("cbbd") << '\n';
  std::cerr << s.longestPalindrome("a") << '\n';

  std::cerr << s.longestPalindrome("bb") << '\n';
}