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
    int ans = 0;
    int dfs(TreeNode* root, int start){
        if(root == NULL) return 0;
        int left = dfs(root->left, start);
        int right = dfs(root->right, start);

        if(root->val == start){
            ans = max(ans, max(left, right));
            return -1;
        }
        if(left < 0){
            ans = max(ans, abs(left) + right);
            return left - 1;
        }
        if(right < 0){
            ans = max(ans, abs(right) + left);
            return right - 1;
        }
        return max(left, right) + 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return ans;
    }
};