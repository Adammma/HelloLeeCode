//
// Created by Adam on 2023/9/13.
//
/* 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1] */
#include "iostream"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //快慢指针，当快指针走过n个节点后，慢指针开始走，当快指针到头的时候，慢指针指向的就是要删除的节点
        ListNode* fastIndex = head;
        ListNode* slowIndex = head;
        ListNode* virHead = new ListNode(0);
        ListNode* preSlow = virHead;
        virHead->next = head;
        int count = 1;
        if (head->next == nullptr&&n ==1) return nullptr;
        while (fastIndex->next!= nullptr){
            if (count<n){
                fastIndex = fastIndex->next;
                count++;
            } else{
                fastIndex = fastIndex->next;
                slowIndex = slowIndex->next;
                preSlow = preSlow->next;
            }
        }
        if (count<n){
            return nullptr;
        } else{
            preSlow->next = slowIndex->next;
        }
        return virHead->next;
    }
};