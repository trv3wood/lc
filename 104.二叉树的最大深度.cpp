/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (78.98%)
 * Likes:    2110
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 2.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树 root ，返回其最大深度。
 *
 * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数量在 [0, 10^4] 区间内。
 * -100 <= Node.val <= 100
 *
 *
 */

#include <queue>
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution {
public:
  //   int maxDepth(TreeNode *root) {
  //     if (!root) {
  //       return 0;
  //     }
  //     return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  //   }
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto top = q.front();
        q.pop();
        if (top->left) {
          q.push(top->left);
        }
        if (top->right) {
          q.push(top->right);
        }
      }
      depth++;
    }
    return depth;
  }
};
// @lc code=end
