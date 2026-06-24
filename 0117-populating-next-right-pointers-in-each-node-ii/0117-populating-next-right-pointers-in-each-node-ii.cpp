/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* curr = q.front();
                q.pop();
                if(i == n-1 || q.empty()){
                    curr->next = nullptr;
                }else{
                    curr->next = q.front();
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};


/* 
Linking the nodes TC -> O(N) SC -> O(1)
Node* curr = root;
        while(curr){
            Node dummy(0);
            Node* tail = &dummy;

            while(curr){
                if(curr->left){
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if(curr->right){
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
              curr = dummy.next;
        }
           return root;

*/