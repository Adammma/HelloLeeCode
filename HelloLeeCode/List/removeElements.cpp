//
// Created by Adam on 2023/9/7.
//

/** 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]

 */
/**
* Definition for singly-linked list.
*/
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
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) return head;
        else {

            while (head != NULL && head->val == val) {
                ListNode *tmpNode = head;
                head = head->next;
                delete tmpNode ;
            }
            ListNode *currentNode = head;
            while (currentNode != nullptr && currentNode->next != nullptr) {
                if (currentNode->next->val == val) {
                    ListNode *deleteNode = currentNode->next;
                    currentNode->next = currentNode->next->next;
                    delete deleteNode;
                } else {
                    currentNode = currentNode->next;
                }
            }
        }
        return head;
    }
};