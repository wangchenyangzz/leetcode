// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * listNode = new ListNode(-1);
        ListNode * head = listNode;
        int flag = 0;
        int num = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int cflag = 0;
            if (l1 == NULL && l2 == NULL) {
                break;
            } else if(l1 != NULL && l2 == NULL) {
                cflag = 0;
                num = (l1->val + flag) % 10;
                if (l1->val + flag >= 10) {
                    cflag = 1;
                }
                l1 = l1->next;
            } else if(l1 == NULL && l2 != NULL) {
                cflag = 0;
                num = (l2->val + flag) % 10;
                if (l2->val + flag >= 10) {
                    cflag = 1;
                }
                l2 = l2->next;
            } else if(l1 != NULL && l2 != NULL) {
                cflag = 0;
                num = (l1->val + l2->val + flag) % 10;
                if (l1->val + l2->val + flag >= 10) {
                    cflag = 1;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            head->next = new ListNode(num);
            head = head->next;
            flag = cflag;
        }
        if (flag == 1) {
            head->next = new ListNode(1);
        }
        return listNode->next;
    }
};

int main() {
    Solution solution;
    ListNode * l1 = new ListNode(6);
    l1->next = new ListNode(7);
    l1->next->next = new ListNode(8);
    
    ListNode * l2 = new ListNode(4);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(6);
    ListNode *node = solution.addTwoNumbers(l1,l2);
    while (node != NULL)
    {
        cout << node->val << endl;
        ListNode * next = node->next;
        node = next;
    }
    
    return 0;
}
