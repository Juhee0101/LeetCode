/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    // size of linked list
    int n = 0;
    struct ListNode *curr = head;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }

    curr = head;
    struct ListNode *nodeList[n];
    for (int i=0; i<n; i++) {
        nodeList[i] = curr;
        curr = curr->next;
    }
        
    curr = head;
    for (int i=0; i<n/2; i++) {
        struct ListNode *last = nodeList[n-1-i];
        last->next = curr->next;
        curr->next = last;
        curr = curr->next->next;
    }    
    curr->next = NULL;
}