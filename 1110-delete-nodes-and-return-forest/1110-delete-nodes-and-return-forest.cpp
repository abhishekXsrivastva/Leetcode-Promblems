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
    unordered_set<int> st;
    vector<TreeNode*> res;
    TreeNode* delHelper(TreeNode* root){
        if(!root) return nullptr;
        root->left = delHelper(root->left);
        root->right = delHelper(root->right);

        if(st.count(root->val)){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);

            return nullptr;
        }else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       for(int &x : to_delete){
        st.insert(x);
       } 
     root = delHelper(root);
       if(root){
        res.push_back(root);
       }
       return res;
    }
};