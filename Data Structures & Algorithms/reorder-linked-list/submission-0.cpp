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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        int size = 0;

        //store them into a stack
        ListNode* curr = head;
        while (curr) {
            stk.push(curr);
            curr = curr->next;
            size++;
        }

        curr = head;
        for (int i=0; i<size/2; i++) {
            ListNode* item = stk.top();
            ListNode* temp = curr->next;
            stk.pop();

            curr->next = item;
            item->next = temp;
            curr = curr->next->next;
        }
        curr->next = nullptr;
    }
};
