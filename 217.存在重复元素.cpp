/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (int& n : nums) {
            if (set.find(n) != set.end()) {
                return true;
            }
            set.insert(n);
        }
        return false;
    }
};
// @lc code=end

