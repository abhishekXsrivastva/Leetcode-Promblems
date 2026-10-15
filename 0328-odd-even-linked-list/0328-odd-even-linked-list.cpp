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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* ohead = NULL;
        ListNode* otail = NULL;

        ListNode* ehead = NULL;
        ListNode* etail = NULL;

        int idx = 1;
        ListNode* temp = head;
        while(temp != NULL) {
            if(idx%2 == 0){
                if(ehead == NULL && etail == NULL) {
                    ehead = etail = temp;
                }else {
                    etail->next = temp;
                    etail = temp;
                }
            }else {
                if(ohead == NULL && otail == NULL) {
                    ohead = otail = temp;
                }else{
                    otail->next = temp;
                    otail = temp;
                }
            }
            idx++;
            temp = temp->next;
       }
       otail->next = ehead;
       if(etail != NULL) {
        etail->next = nullptr;
       }
       return ohead;
        
    }
};