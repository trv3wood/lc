/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (47.88%)
 * Likes:    2572
 * Dislikes: 0
 * Total Accepted:    726.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * 二叉树中的 路径
 * 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中
 * 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include "treenode.h"
#include <algorithm>
#include <climits>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int path_sum = INT_MIN;
  int maxPathSum(TreeNode *root) {
    partialPathSum(root);
    return path_sum;
  }
  int partialPathSum(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left_sum = std::max(partialPathSum(root->left), 0);
    int right_sum = std::max(partialPathSum(root->right), 0);
    path_sum = std::max(path_sum, root->val + left_sum + right_sum);
    return root->val + std::max(left_sum, right_sum);
  }
};
// @lc code=end
