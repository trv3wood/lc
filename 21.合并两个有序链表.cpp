/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (68.15%)
 * Likes:    4016
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 3.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序
 * 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100
 * l1 和 l2 均按 非递减顺序 排列
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  //     ListNode* head = new ListNode(-1, nullptr);
  //     ListNode* curr = head;
  //     while (list1 && list2) {
  //         if (list1->val < list2->val) {
  //             curr->next = list1;
  //             list1 = list1->next;
  //         } else {
  //             curr->next = list2;
  //             list2 = list2->next;
  //         }
  //         curr = curr->next;
  //     }
  //     while (list1) {
  //         curr->next = list1;
  //         curr = curr->next;
  //         list1 = list1->next;
  //     }
  //     while (list2) {
  //         curr->next = list2;
  //         curr = curr->next;
  //         list2 = list2->next;
  //     }
  //     return head->next;
  // }
  
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = new ListNode(-1);
    ListNode *curr = head;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    // 因为 list1 和 list2 各自本身就是有序的，剩余部分直接整段接上即可，不需要逐个节点遍历。
    curr->next = list1 ? list1 : list2;

    return head->next;
  }
};
// @lc code=end
