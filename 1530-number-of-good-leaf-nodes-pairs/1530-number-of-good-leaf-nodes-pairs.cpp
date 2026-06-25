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
    vector<int> countPairsHelper(TreeNode* root, int& distance, int& goodLeafNodes){
        if(!root){
            return {0};
        }

        if(!root->left && !root->right){
            return {1};
        }

        vector<int> left = countPairsHelper(root->left, distance, goodLeafNodes);
        vector<int> right = countPairsHelper(root->right, distance, goodLeafNodes);

        for(int l : left){
            for(int r : right){
                if((l && r) && l + r <= distance){
                    goodLeafNodes++;
                }
            }
        }


        vector<int> currDis;
        for(int l : left){
            if(l && l+1 <= distance)
            currDis.push_back(l+1);
        }

        for(int r : right){
            if(r && r+1 <= distance)
            currDis.push_back(r+1);
        }

        return currDis;

    }
    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;
        countPairsHelper(root, distance, goodLeafNodes);
        return goodLeafNodes;
    }
};