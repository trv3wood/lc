/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (49.10%)
 * Likes:    2855
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.1M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums
 * ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,0,1,2]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s;
    int ans = 0;
    for (const auto &n : nums) {
      s.insert(n);
    }
    while (!s.empty()) {
      int n = *s.begin();
      int len = 0;
      for (int t = n; s.find(t) != s.end(); len++) {
        s.erase(t++);
      }
      for (int t = n - 1; s.find(t) != s.end(); len++) {
        s.erase(t--);
      }
      ans = std::max(ans, len);
    }
    return ans;
  }
};
// @lc code=end
/*
 * s.erase() 的权衡：在 unordered_set 中，erase(key) 的平均复杂度是 $O(1)$，但在最坏情况下（哈希冲突严重）会退化。
 * 你的写法通过 erase 减少了哈希冲突的概率（表越来越小），但频繁的删除操作可能会导致哈希表内部的 rehash 或节点调整。
 * 面试加分说辞：“我使用 erase 是为了确保每个元素只进入逻辑一次，避免了重复查询，空间复杂度 $O(n)$，时间复杂度稳定在 $O(n)$。
 * ”为什么不用 std::set？：面试官必问：set 底层是红黑树，$O(n \log n)$；unordered_set 底层是哈希表，平均 $O(n)$。这道题严禁使用 set。
 */