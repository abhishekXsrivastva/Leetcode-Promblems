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
    int getLength(ListNode* head){
        ListNode* tail = head;
       int len = 1;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        return len;

    }

    ListNode* getKthNode(ListNode* head, int k){
        ListNode* temp = head;
        int cnt = 1;
        while(temp){
            if(k == cnt) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

       /* ListNode* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        } */
        int length = getLength(head);
        if(k % length == 0) return head;
        k = k % length;


        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;

        ListNode* newLastNode = getKthNode(head, length - k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
        
    }
};