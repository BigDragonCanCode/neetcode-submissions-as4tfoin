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
    bool isThereItemToMerge(vector<ListNode*>& lists) {
        for (ListNode* l: lists) {
            if (l)
                return true;
        }
        return false;
    }

    //find the smallest
    ListNode* itemToMerge(vector<ListNode*>& lists) {
        int idx = -1;
        for (int i=0; i<lists.size(); i++) {
            if (lists[i] && (idx == -1 || lists[i]->val < lists[idx]->val))
                idx = i;
        }
        ListNode* item = lists[idx];
        lists[idx] = lists[idx]->next;
        return item;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode result(0);
        ListNode* node = &result;

        while (isThereItemToMerge(lists)) {
            ListNode* item = itemToMerge(lists);
            node->next = item;
            node = node->next;
        }
        node->next = nullptr;

        return result.next;
    }
};
