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
    int longest_path = 0;
    void longestZigZagHelper(TreeNode* root, int path, bool goleft){
        if(root == nullptr) return;

        longest_path = max(longest_path, path);
        if(goleft){
            longestZigZagHelper(root->left, path+1, false);
            longestZigZagHelper(root->right, 1, true);
        }else{
            longestZigZagHelper(root->right, path+1, true);
            longestZigZagHelper(root->left, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        longestZigZagHelper(root, 0, true);
        return longest_path;
    }
};
/* 
 int longest_path = 0;
    void dfs(TreeNode* root, int left, int right){
        if(root == nullptr) return;
        longest_path = max({longest_path, left, right});

        dfs(root->left, right+1, 0);
        dfs(root->right, 0, left+1);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return longest_path;
*/