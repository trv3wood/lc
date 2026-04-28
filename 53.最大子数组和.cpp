/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (56.61%)
 * Likes:    7379
 * Dislikes: 0
 * Total Accepted:    2.6M
 * Total Submissions: 4.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums
 * ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */
#include "dbg.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
// #define debug(...)

class Solution {
public:
  // int maxSubArray(vector<int> &nums) {
  //   int n = nums.size();
  //   vector<int> dp(n, INT_MIN);
  //   int max_sum = dp[0] = nums[0];
  //   for (int i = 1; i < n; i++) {
  //     dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
  //     max_sum = std::max(dp[i], max_sum);
  //   }
  //   return max_sum;
  // }
  // optimized version
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int dp;
    int max_sum = dp = nums[0];
    for (int i = 1; i < n; i++) {
      dp = std::max(nums[i], dp + nums[i]);
      max_sum = std::max(dp, max_sum);
    }
    return max_sum;
  }
};
// @lc code=end
/*
 * dp[0] = nums[0]
 * dp[i] = max(nums[i], dp[i - 1] + nums[i])
 */
int main() {
  Solution s;
  vector<int> nums = {5, 4, -1, 7, 8};
  std::cerr << s.maxSubArray(nums) << '\n';
  nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cerr << s.maxSubArray(nums) << '\n';
  nums = {1};
  std::cerr << s.maxSubArray(nums) << '\n';
  nums = {-2, 1};
  std::cerr << s.maxSubArray(nums) << '\n';
}