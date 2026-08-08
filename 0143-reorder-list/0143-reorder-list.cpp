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

    // Find middle and split the list
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Head of second half
        ListNode* second = slow->next;

        // Break the first half
        slow->next = NULL;

        return second;
    }

    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return;
        }

        // 1. Split into two halves
        ListNode* rightHead = splitAtMid(head);

        // 2. Reverse second half
        ListNode* right = reverse(rightHead);

        // 3. Merge alternately
        ListNode* left = head;

        while (right != NULL) {

            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }
    }
};