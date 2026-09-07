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
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

       ListNode* dummy = new ListNode();
       ListNode* temp = dummy;

       int carry = 0;

       while(l1 != nullptr || l2 != nullptr || carry){
        int sum = 0;
        if(l1){
           sum += l1->val;
           l1 = l1->next;
        }
        if(l2){
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next = newNode;
        temp = temp->next;

       }
       return reverseLL(dummy->next);
    }
};