/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (69.67%)
 * Likes:    2680
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.3M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 解释：
 * 
 * 
 * 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
 * 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 
 * 输出: [["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     std::vector<std::vector<std::string>> ans;
    //     std::unordered_map<std::string, int> m;
    //     int idx = 0;
    //     for (int i = 0; i < strs.size(); i++) {
    //         std::string s = strs[i];
    //         std::sort(s.begin(), s.end());
    //         if (m.find(s) == m.end()) {
    //             ans.push_back({strs[i]});
    //             m.insert({s, idx++});
    //         } else {
    //             ans[m[s]].push_back(strs[i]);
    //         }
    //     }
    //     return ans;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> ans;
        std::unordered_map<std::string, int> m;
        int idx = 0;
        for (const auto& s : strs) {
            std::string key(26, 0);
            for (const auto& c: s) {
                ++key[c - 'a'];
            }
            if (m.find(key) == m.end()) {
                ans.push_back({s});
                m.insert({key, idx++});
            } else {
                ans[m[key]].push_back(s);
            }
        }
        return ans;
    }
};
// @lc code=end

