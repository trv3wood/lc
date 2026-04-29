/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (64.02%)
 * Likes:    1922
 * Dislikes: 0
 * Total Accepted:    821.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 *
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度
 * 。这条路径可能经过也可能不经过根节点 root 。
 *
 * 两节点之间路径的 长度 由它们之间边数表示。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 10^4] 内
 * -100 <= Node.val <= 100
 *
 *
 */

#include "dbg.h"
#include <algorithm>
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
//
// Definition for a binary tree node.
class Solution {
public:
  int d = 0;
  int diameterOfBinaryTree(TreeNode *root) {
    walk(root);
    return d;
  }
  int walk(TreeNode *root) {
    if (!root)
      return 0;

    int left = walk(root->left);
    int right = walk(root->right);

    d = std::max(d, left + right);

    return 1 + std::max(left, right);
  }
};
// @lc code=end
int main() {
  TreeNode *root = new TreeNode(1, new TreeNode(2), nullptr);
  Solution s;
  debug(s.diameterOfBinaryTree(root));
}