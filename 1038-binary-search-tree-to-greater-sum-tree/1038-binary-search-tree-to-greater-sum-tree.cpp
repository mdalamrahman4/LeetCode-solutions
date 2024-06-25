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
    TreeNode* bstToGst(TreeNode* root) {
        int accsum=0;
        sumnode(root,accsum);
        return root;
    }
    void sumnode(TreeNode*root,int &accsum){
        if(!root)   return;
        sumnode(root->right,accsum);
        root->val+=accsum;
        accsum=root->val;
        sumnode(root->left,accsum);
    }
};