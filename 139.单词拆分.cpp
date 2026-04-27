/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode.cn/problems/word-break/description/
 *
 * algorithms
 * Medium (59.99%)
 * Likes:    2960
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.7M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 * 注意，你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s 和 wordDict[i] 仅由小写英文字母组成
 * wordDict 中的所有字符串 互不相同
 * 
 * 
 */
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string_view> set;
        vector<int> splits{0};
        for (const auto& w : wordDict) {
            set.insert(w);
        }
        string_view v(s);
        for (int i = 0; i < dp.size(); i++) {
            for (int j_it = splits.size() - 1; j_it >= 0; j_it--) {
                int j = splits[j_it];
                auto sub = v.substr(j, i - j);
                if (j < i && dp[j] && set.find(sub) != set.end()) {
                    dp[i] = true;
                    splits.push_back(i);
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
 
// Author: Gemini
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    // 1. 建立哈希表，并记录字典中最长单词的长度，进一步剪枝
    unordered_set<string_view> dict;
    size_t max_len = 0;
    for (const auto& w : wordDict) {
        dict.insert(w);
        max_len = max(max_len, w.length());
    }

    // 2. 你的 splits 优化思路很好，我们稍微优化一下遍历逻辑
    vector<int> valid_indices{0};
    
    string_view sv(s);

    for (int i = 1; i <= n; i++) {
        // 从后往前遍历有效分割点，通常能更快找到匹配
        for (int j_it = valid_indices.size() - 1; j_it >= 0; j_it--) {
            int j = valid_indices[j_it];
            
            // 剪枝：如果当前子串长度超过了字典最长单词，直接跳过
            if (i - j > max_len) continue; 

            if (dict.count(sv.substr(j, i - j))) {
                dp[i] = true;
                valid_indices.push_back(i);
                break; // 只要找到一个合法的分割点，dp[i] 就是 true
            }
        }
    }
    return dp[n];
}

/*
dp[0] = true
dp[i] = if j < i && dp[j] == true && str[j..i) found_in_dict { true } else { false }
*/
int main() {
    vector<string> dict{"aaaa", "aaa"};
    Solution s;
    std::cout <<  s.wordBreak("aaaaaaa", dict);
}