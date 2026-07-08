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
    int maxD = 0;
    unordered_map<int, int>mpp;

    void depth(TreeNode* root, int d){
        if(root == NULL) return;
        maxD = max(maxD, d);
        mpp[root->val] = d;
        depth(root->left, d+1);
        depth(root->right, d+1);
    }

    TreeNode* LCA(TreeNode* root){
        if(root == nullptr || mpp[root->val] == maxD) return root;
        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);

        return LCA(root);
    }
};