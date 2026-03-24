#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> m;
    for (size_t i = 0; i < nums.size(); i++) {
      if (m.find(nums[i]) !=  m.end()) {
        return vector<int>{m[nums[i]], static_cast<int>(i)};
      }
      m.insert({target - nums[i], i});
    }
    return vector<int>{};
  }
};
// @lc code=end
