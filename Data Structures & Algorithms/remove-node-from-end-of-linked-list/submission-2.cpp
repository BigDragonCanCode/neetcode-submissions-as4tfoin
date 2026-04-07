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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //the gap between the 2 pointers is n
        ListNode* prev = nullptr;
        ListNode* curr1 = head;
        ListNode* curr2 = head;

        for (int i=0; i<n; i++) {
            if (curr2 == nullptr)
                return nullptr;
            curr2 = curr2->next;
        }

        while (curr2) {
            prev = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        //remove the item
        if (!prev) return head->next; //means the item we need to remove is the first item
        prev->next = curr1->next;
        return head;
    }
};
