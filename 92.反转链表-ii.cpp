/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode.cn/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (58.15%)
 * Likes:    2079
 * Dislikes: 0
 * Total Accepted:    732K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
 * 
 */

// Definition for singly-linked list.
#include <cassert>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            ListNode* head = pre->next;
            pre->next = next;
            next->next = head;
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
    s.reverseBetween(dummy->next, 2, 4);
    while (dummy) {
        std::cout << dummy->val << ' ';
        dummy = dummy->next;
    }
}
