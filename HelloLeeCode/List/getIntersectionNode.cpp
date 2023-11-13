//
// Created by Adam on 2023/9/14.
//

/* 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。*/

#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int aLength = 0;
        int bLength = 0;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        if (headA == nullptr || headB == nullptr) return nullptr;
        while (tmpA->next != nullptr) {
            aLength++;
            tmpA = tmpA->next;
        }
        while (tmpB->next != nullptr) {
            bLength++;
            tmpB = tmpB->next;
        }
        int x = abs(aLength - bLength);
        tmpA = headA;
        tmpB = headB;
        if (aLength > bLength) {
            for (int i = 0; i < x; ++i) {
                tmpA = tmpA->next;
            }
        } else if (aLength < bLength) {
            for (int i = 0; i < x; ++i) {
                tmpB = tmpB->next;
            }
        }

        while (tmpA != nullptr && tmpB != nullptr) {
            if (tmpA == tmpB){
                return tmpA;
            } else {
                tmpA = tmpA->next;
                tmpB = tmpB->next;
            }
        }
        return nullptr;
    }
};