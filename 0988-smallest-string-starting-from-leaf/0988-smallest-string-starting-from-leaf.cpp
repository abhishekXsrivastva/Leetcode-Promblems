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
    string res = "";
    void smallestFromLeafHelper(TreeNode* root, string curr){
        if(!root) return;
         curr = char(root->val + 'a') + curr;

         if(!root->left && !root->right){
            if(res == "" || res > curr){
                res = curr;
            }
            return;
         }
         smallestFromLeafHelper(root->left, curr);
         smallestFromLeafHelper(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        smallestFromLeafHelper(root, "");
        return res;
    }
};