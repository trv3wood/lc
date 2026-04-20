/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (70.61%)
 * Likes:    2285
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 2.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
 * （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 *
 *
 */

#include <queue>
#include <vector>
using namespace std;

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
  // 这版代码逻辑是对的，但在大厂面试中，这个写法属于“能跑通，但不够优雅”的范畴。
  // 你用了一个带 pos
  // 的结构体来记录层级。虽然这种做法很稳，但多开辟了一个结构体的开销。 struct N
  // {
  //     TreeNode* node;
  //     int pos;
  // };
  // vector<vector<int>> levelOrder(TreeNode* root) {
  //     std::queue<N> q;
  //     vector<vector<int>> ans;
  //     q.push({root, 0});
  //     while (!q.empty()) {
  //         auto front = q.front();
  //         if (front.node == nullptr) {
  //             q.pop();
  //             continue;
  //         }
  //         if (front.pos < ans.size()) {
  //             ans[front.pos].push_back(front.node->val);
  //         } else {
  //             ans.push_back({front.node->val});
  //         }
  //         q.push({front.node->left, front.pos + 1});
  //         q.push({front.node->right, front.pos + 1});
  //         q.pop();
  //     }
  //     return ans;
  // }
  
  // 利用每一层循环开始时 queue 的长度来锁定当前层的节点数
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (!root) {
        return ans;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> current_level;
      for (int i = 0; i < size; i++) {
        auto front = q.front();
        q.pop();
        current_level.push_back(front->val);
        if (front->left) {
          q.push(front->left);
        }
        if (front->right) {
          q.push(front->right);
        }
      }
      ans.push_back(std::move(current_level));
    }
    return ans;
  }
};
// @lc code=end
