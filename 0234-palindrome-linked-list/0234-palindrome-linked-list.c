/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// 팰린드롬 여부를 확인하는 함수
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // 빠른 포인터와 느린 포인터를 사용하여 리스트의 중간을 찾음
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 중간부터 리스트의 끝까지를 역순으로 뒤집음
    slow->next = reverseList(slow->next);
    slow = slow->next; // 역순으로 뒤집힌 부분의 첫 노드

    // 리스트의 시작부터 중간까지와 뒤집힌 부분을 비교
    while (slow != NULL) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }

    return true;
}