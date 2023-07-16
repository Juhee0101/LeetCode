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

        int targetIdx = findTargetIndex(head, n);
        ListNode* newHead = findNewHead(head, n, targetIdx);
        
        return newHead;
    }

private:
    int findTargetIndex(ListNode* head, int n){
        ListNode* temp = head;
        int len=0;

        while(temp) {
            len++;
            temp = temp->next;
        }

        return len-n;
    }

    ListNode* findNewHead(ListNode* head, int n, int targetIdx){
        ListNode* newHead = head;

        if (targetIdx == 0) {
            return head->next;
        }

        for (int idx=0; idx<(targetIdx-1); idx++) {
            head = head->next;
        }

        head->next = head->next->next;

        return newHead;
    }

};