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
    //return 1 means carry
    void helper(ListNode* l1, ListNode* l2, ListNode* prev, int carry) {
        
        if (l1 == nullptr && l2 == nullptr) {
            if (carry) {
                prev->next = new ListNode(1);
            }
            return;
        }
        if (l1 == nullptr) {
            prev->next = new ListNode((l2->val+carry)%10);
            return helper(l1, l2->next, prev->next, (l2->val+carry>=10));
        }
        if (l2 == nullptr) {
            prev->next = new ListNode((l1->val+carry)%10);
            return helper(l1->next, l2, prev->next, (l1->val+carry>=10));
        }

        int value = l1->val + l2->val;
        prev->next = new ListNode((value+carry)%10);
        helper(l1->next, l2->next, prev->next, (value+carry>=10));
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        helper(l1, l2, &head, 0);

        return head.next;
    }
};
