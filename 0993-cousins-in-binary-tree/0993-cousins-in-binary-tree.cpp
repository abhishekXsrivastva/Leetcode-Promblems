/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            bool flagX = false, flagY = false;
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && node->right){
                    int left = node->left->val;
                    int right = node->right->val;

                    if((left == x && right == y) ||
                      (left == y && right == x)) return false;
                }
                if(node->left){
                    if(node->left->val == x) flagX = true;
                    if(node->left->val == y) flagY = true;
                    q.push(node->left);

                }
                if(node->right){
                    if(node->right->val == x) flagX= true;
                    if(node->right->val == y) flagY = true;
                    q.push(node->right);
                }
            }
            if(flagX && flagY) return true;
            if(flagX || flagY) return false;
        }
        return false;
    }
};