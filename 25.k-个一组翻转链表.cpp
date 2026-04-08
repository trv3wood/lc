/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (69.94%)
 * Likes:    2820
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
 * 
 * 
 * 
 * 
 */


// Definition for singly-linked list.
#include <cassert>
#include <cfenv>
#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int node_count = 0;
        while (cur) {
            cur = cur->next;
            node_count++;
        }
        int group_count = node_count / k;
        ListNode* pre = new ListNode(0, head);
        ListNode* dummy = pre;
        for (int i = 0; i < group_count; i++) {
            cur = pre->next;
            for (int j = 0; j < k - 1; j++) {
                ListNode* next = cur->next;
                cur->next = next->next;
                ListNode* group_begin = pre->next;
                pre->next = next;
                next->next = group_begin;
            }
            pre = cur;
        }
        return dummy->next;
    }
};
// @lc code=end

int main() {
    std::vector<int> v = {1,2,3,4,5};
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int n: v) {
        cur->next = new ListNode(n);
        cur = cur->next;
    }
    Solution s;
    dummy = s.reverseKGroup(dummy->next, 2);
    while (dummy) {
        std::cout << dummy->val << ' ';
        dummy = dummy->next;
    }
}
