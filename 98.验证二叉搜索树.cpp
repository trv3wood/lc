/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (40.74%)
 * Likes:    2760
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.5M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 *
 * 有效 二叉搜索树定义如下：
 *
 *
 * 节点的左子树只包含 严格小于 当前节点的数。
 * 节点的右子树只包含 严格大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,1,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 */
#include "treenode.h"
#include <algorithm>
#include <climits>
#include <utility>
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
  int l = INT_MAX;
  int r = INT_MIN;
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (!isValidBST(root->left)) {
      return false;
    }
    if (!isValidBST(root->right)) {
      return false;
    }
    return true;
  }
  bool walk(TreeNode* root, int* left_extremum, int* right_extremum) {
    if (!root) {
      return true;
    }
    if (!walk(root->left, left_extremum, nullptr)) {
      return false;
    }
    if (!walk(root->right, nullptr, right_extremum)) {
      return false;
    }
    if (root->val <= *left_extremum) {
      return false;
    }
    if (root->val >= *right_extremum) {
      return false;
    }
    return true;
  }
};
// @lc code=end
/*
          5
        4   6
          3   7
*/