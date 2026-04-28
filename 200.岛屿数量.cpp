/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (63.86%)
 * Likes:    2982
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:
 * '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和
 * '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ['1','1','1','1','0'],
 * ['1','1','0','1','0'],
 * ['1','1','0','0','0'],
 * ['0','0','0','0','0']
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ['1','1','0','0','0'],
 * ['1','1','0','0','0'],
 * ['0','0','1','0','0'],
 * ['0','0','0','1','1']
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] 的值为 '0' 或 '1'
 *
 *
 */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#include "dbg.h"
// @lc code=start
#define debug(...)
class Solution {
public:
  int m;
  int n;
  std::queue<std::pair<int, int>> q;
  void extend(vector<vector<char>> &grid, int x, int y) {
    if (x >= 1 && grid[x - 1][y] == '1') {
      q.push({x - 1, y});
      grid[x - 1][y] = '0';
    }
    if (x + 1 < m && grid[x + 1][y] == '1') {
      q.push({x + 1, y});
      grid[x + 1][y] = '0';
    }
    if (y >= 1 && grid[x][y - 1] == '1') {
      q.push({x, y - 1});
      grid[x][y - 1] = '0';
    }
    if (y + 1 < n && grid[x][y + 1] == '1') {
      q.push({x, y + 1});
      grid[x][y + 1] = '0';
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          q.push({i, j});
          grid[i][j] = '0';
          while (!q.empty()) {
            const auto [x, y] = q.front();
            debug(x, y);
            q.pop();
            extend(grid, x, y);
          }
          ans++;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
// DFS by Deepseek
class Solution2 {
  int m;
  int n;
  std::queue<std::pair<int, int>> q;
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};

  void extend(vector<vector<char>> &grid, int x, int y) {
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
        q.push({nx, ny});
        grid[nx][ny] = '0'; // 入队即标记，防止重复入队
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          q.push({i, j});
          grid[i][j] = '0';
          while (!q.empty()) {
            const auto [x, y] = q.front();
            debug(x, y);
            q.pop();
            extend(grid, x, y);
          }
          ans++;
        }
      }
    }
    return ans;
  }
};
int main() {
  vector<vector<char>> v = {{'0', '1', '0'}, {'1', '0', '1'}, {'0', '1', '0'}};
  Solution s;
  debug(s.numIslands(v));
}