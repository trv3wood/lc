/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode.cn/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (72.71%)
 * Likes:    1947
 * Dislikes: 0
 * Total Accepted:    572.9K
 * Total Submissions: 789.2K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Trie（发音类似 "try"）或者说 前缀树
 * 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
 *
 * 请你实现 Trie 类：
 *
 *
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回
 true（即，在检索之前已经插入）；否则，返回
 * false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为
 prefix ，返回 true
 * ；否则，返回 false 。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 *
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
 *
 *
 */

#include <map>
#include <string>
#include <type_traits>
using namespace std;
// @lc code=start
class Trie {
public:
  std::map<char, Trie *> child;
  bool end = false;
  Trie() {}
  Trie(int end) : end(end) {}

  void insert(string word) {
    Trie *node = this;
    for (char c : word) {
      if (!node->child.count(c)) {
        node->child[c] = new Trie();
      }
      node = node->child[c];
    }
    node->end = true;
  }

  bool search(string word) {
    Trie *t = this;
    for (int i = 0; i < word.size(); i++) {
      auto f = t->child.find(word[i]);
      if (f == t->child.end()) {
        return false;
      }
      t = f->second;
    }
    return t->end;
  }

  bool startsWith(string prefix) {
    Trie *t = this;

    for (int i = 0; i < prefix.size(); i++) {
      auto f = t->child.find(prefix[i]);
      if (f == t->child.end()) {
        return false;
      }
      t = f->second;
    }
    return true;
  }
  ~Trie() {
    for (auto &[ch, child] : child) {
      delete child;
    }
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
class Trie2 {
  Trie2 *children[26] = {};
  bool isEnd = false;

public:
  ~Trie2() {
    for (auto *child : children) {
      delete child;
    }
  }

  void insert(const string &word) {
    Trie2 *node = this;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        node->children[idx] = new Trie2();
      }
      node = node->children[idx];
    }
    node->isEnd = true;
  }

  bool search(const string &word) {
    Trie2 *node = this;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->children[idx])
        return false;
      node = node->children[idx];
    }
    return node->isEnd;
  }

  bool startsWith(const string &prefix) {
    Trie2 *node = this;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!node->children[idx])
        return false;
      node = node->children[idx];
    }
    return true;
  }
};
