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
    int goodNodesHelper(TreeNode* root, int maxVal){
        if(!root) return 0;
         int res = (root->val >= maxVal) ? 1 : 0;
         maxVal = max(root->val, maxVal);

         res += goodNodesHelper(root->left, maxVal);
         res += goodNodesHelper(root->right, maxVal);

         return res; 
    }
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, root->val);
    }
};