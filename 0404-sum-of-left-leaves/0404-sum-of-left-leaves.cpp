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
    int lefts(TreeNode*root,bool flag){
        if(!root)   return 0;
        if(!root->left && !root->right && flag){
            return root->val;
        }
        return lefts(root->left,true)+lefts(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return lefts(root->left,true)+lefts(root->right,false);
    }
};