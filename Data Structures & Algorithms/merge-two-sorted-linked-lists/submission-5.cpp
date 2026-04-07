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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1; 

        ListNode* result = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        if (curr1->val < curr2->val) {
            result = curr1;
            curr1 = curr1->next;
        } else {
            result = curr2;
            curr2 = curr2->next;
        }

        ListNode* result_end = result;

        while (curr1 || curr2) {
            if (!curr1) {
                result_end->next = curr2;
                break;
            } else if (!curr2) {
                result_end->next = curr1;
                break;
            }
            
            if (curr1->val < curr2->val) {
                result_end->next = curr1;
                curr1 = curr1->next;
            } else {
                result_end->next = curr2;
                curr2 = curr2->next;
            }
            result_end = result_end->next;
        }
        return result;

        
    }
};
