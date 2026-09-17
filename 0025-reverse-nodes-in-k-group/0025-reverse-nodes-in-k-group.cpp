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
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

    ListNode* KthNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while(temp){
            ListNode* kNode = KthNode(temp, k);
            if(kNode == nullptr){
                if(prevNode) prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kNode->next;
            kNode->next = nullptr;
            reverseLL(temp);
            if(head == temp){
                head = kNode;
            }else{
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
        
    }
};