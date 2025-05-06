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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(); //This will be the linked list that will hold the sum of two nodes
        ListNode* res = sum; //This pointer will be used to traverse the sum list
        int total = 0, carry = 0; // The total is the sum of the two pointers and carry is used to add another node, the carry, in case of it being over 10 (Example 3)
        while(l1 || l2 || carry) {
            total = carry;
        
            if(l1) {
                total += l1->val; // add total to node
                l1 = l1->next;// move to next one
            }
            if(l2) {
                total += l2->val; // add total to node
                l2 = l2->next;// move to next one
            }

            int num = total % 10; //get the remainder
            carry = total / 10; // initalize a new node, should always be zero
            sum->next = new ListNode(num);
            sum = sum ->next; // carry remainder to new node
        }
        ListNode* result = res->next;
        delete res;
        return result;
    }
};