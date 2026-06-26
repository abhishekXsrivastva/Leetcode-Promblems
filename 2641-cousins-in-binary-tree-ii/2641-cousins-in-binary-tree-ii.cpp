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
    vector<int> levelSum;
    void dfs1(TreeNode* root, int level){
        if(!root) return;
        if(level == levelSum.size()){
            levelSum.push_back(0);
        }
        levelSum[level] += root->val;
        dfs1(root->left, level + 1);
        dfs1(root->right, level + 1);
    }

    void dfs2(TreeNode* root, int level){
        if(!root) return;
        int childSum = 0;
        if(root->left) childSum += root->left->val;
        if(root->right) childSum += root->right->val;

        if(root->left) root->left->val = levelSum[level+1] - childSum;
        if(root->right) root->right->val = levelSum[level+1] - childSum;

        dfs2(root->left, level+1);
        dfs2(root->right, level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, 0);
        root->val = 0;
        dfs2(root, 0);

        return root;
    }
};