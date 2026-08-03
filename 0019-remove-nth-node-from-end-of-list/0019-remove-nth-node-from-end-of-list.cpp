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
    int size(ListNode* head) {
        int sz = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            sz++;
            temp = temp->next;
        }

        return sz;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int sz = size(head);

        // Delete first node
        if (n == sz) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = head;

        // Move prev to node before the one to delete
        for (int i = 1; i < (sz - n); i++) {
            prev = prev->next;
        }

        ListNode* toDel = prev->next;
        prev->next = toDel->next;
        delete toDel;

        return head;
    }
};