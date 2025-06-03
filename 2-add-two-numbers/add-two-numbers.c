/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = l1;
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode *curr = temp1, *prev = dummy;

    int sum = 0, carry = 0;

    while(temp1 != NULL && temp2 !=NULL) {
        sum = temp1->val + temp2->val + carry;
        carry = sum / 10;
        temp1->val = sum % 10;

        prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp2 != NULL){
        prev->next = temp2;
        temp1 = temp2;
    }
    
    while(temp1 != NULL) {
        sum = temp1->val + carry;
        carry = sum / 10;
        temp1->val = sum % 10;

        prev = temp1;
        temp1 = temp1->next;
    }

    if(carry > 0) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        prev->next = newNode;
    }

    return dummy->next;
}