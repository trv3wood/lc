/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (70.20%)
 * Likes:    2348
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为
 * “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 *
 *
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 *
 *
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 *
 *
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 *
 *
 */

// #include <vector>
// @lc code=start
class Solution {
public:
  // 二维数组
  // int uniquePaths(int m, int n) {
  //   std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
  //   dp[0][0] = 1;
  //   for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //       if (i > 0) {
  //         dp[i][j] += dp[i - 1][j];
  //       }
  //       if (j > 0) {
  //         dp[i][j] += dp[i][j - 1];
  //       }
  //     }
  //   }
  //   return dp[m - 1][n - 1];
  // }
  // 一维滚动数组
  // int uniquePaths(int m, int n) {
  //   std::vector<int> dp(n, 0);
  //   dp[0] = 1;
  //   for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //       if (j > 0) {
  //         dp[j] += dp[j - 1];
  //       }
  //     }
  //   }
  //   return dp[n - 1];
  // }
  // 数学公式 C_{m + n - 2}^{m - 1}
  // 总共走 (m - 1) + (n - 1) 步，其中 (m - 1) 步必须向下
  int uniquePaths(int m, int n) {
    int div = 1;
    long long ans = 1;
    for (int i = m; i <= m + n - 2; i++) {
      ans *= i;
      if (div < n) {
        ans /= div++;
      }
    }
    while (div < n) {
      ans /= div++;
    }
    return ans;
  }
  
};
// @lc code=end

/*
 * dp[i][j] = dp[i - 1] + dp[i][j - 1]
 */
