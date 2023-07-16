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
        int len=0, target;
        ListNode* newHead = head;
        ListNode* temp = head;

        while(temp) {
            len++;
            temp = temp->next;
        }

        target = len-n;

        if (target == 0) {
            return head->next;
        }

        for (int idx=0; idx<(target-1); idx++) {
            head = head->next;
        }
        head->next = head->next->next;
        return newHead;
    }
};