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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = head;

        while(temp){
            if(temp->next && temp->val == temp->next->val){
                int duplicateVal = temp->val;

                while(temp && temp->val == duplicateVal){
                    ListNode* duplicateNode = temp;
                    temp = temp->next;
                    delete(duplicateNode);
                }
                prev->next = temp;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }

       return dummy.next;
    }
};