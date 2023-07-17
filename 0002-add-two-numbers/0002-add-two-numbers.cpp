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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode head(0);
        ListNode* curr = &head;
        int digit = 1, totVal;
        bool upOne = false;

        while (l1 || l2 || upOne) {
            if (l1 && l2) {
                totVal = l1->val + l2->val;}
            else if (l1) {
                totVal = l1->val;}
            else if (l2) {
                totVal = l2->val;}
            else {totVal = 0;}

            if (upOne) {totVal = totVal + 1;}
            
            curr->next = new ListNode(totVal % 10);
            if (totVal >= 10) {
                upOne = true;}
            else {
                upOne = false;}
            curr = curr->next;

            if (l1) {l1 = l1->next;}
            if (l2) {l2 = l2->next;}
        }
        return head.next;
    }
};