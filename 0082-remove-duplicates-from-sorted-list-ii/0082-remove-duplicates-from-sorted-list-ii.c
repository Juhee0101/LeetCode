/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));

    dummy->next = head;
    struct ListNode* pre = dummy;
    struct ListNode* cur = head;

    while(cur != NULL){
        while(cur->next != NULL && pre->next->val == cur->next->val){
            cur = cur->next;
        }
        if(pre->next == cur){ //중복이 없으면 다음으로 넘어감
            pre = pre->next;
        }else{ //중복이 있으면 cur 다음으로 넘어가서 중복 제껴줌
            pre->next = cur->next;
            cur = cur->next; 
        }
    }
    return dummy->next;
}