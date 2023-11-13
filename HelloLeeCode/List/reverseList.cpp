//
// Created by Adam on 2023/9/11.
//
/* 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。 */
 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //头插法
        ListNode* result = nullptr;
        while (head != nullptr){
            ListNode* tmp = head->next;
            head->next = result;
            result = head;
            head = tmp;
        }
        return result;
    }
};