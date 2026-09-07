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
   /* ListNode* reverseLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    } */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseLL(l1);
        // l2 = reverseLL(l2);
       
       ListNode* res = nullptr;

       stack<int> stk1;
       stack<int> stk2;

       while(l1){
        stk1.push(l1->val);
        l1 = l1->next;
       }

       while(l2){
        stk2.push(l2->val);
        l2 = l2->next;
       }

       int carry = 0;
    
       while(!stk1.empty() || !stk2.empty() || carry){
        int sum = carry;
        if(!stk1.empty()){
           sum += stk1.top();
           stk1.pop();
        }
        if(!stk2.empty()){
            sum += stk2.top();
            stk2.pop();
        }
        
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        newNode->next = res;
        res = newNode;
       
       }
       return res; 
    }
};