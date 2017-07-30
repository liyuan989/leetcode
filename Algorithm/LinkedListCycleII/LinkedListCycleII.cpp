/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* meet = hasCycle(head);
        if (!meet) {
            return NULL;
        }
        while (meet != head) {
            meet = meet->next;
            head = head->next;
        }
        return meet;
    }

    ListNode* hasCycle(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return slow;
            }
        }
        return NULL;
    }
};

