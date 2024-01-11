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
    int maxAncestorDiff(TreeNode* root) {
        int mx=root->val;
        int mn=root->val;
        int diff=0;
        check(root,mx,mn,diff);
        return diff;
    }
    void check(TreeNode*root,int mx,int mn,int &diff)
    {
        if(!root) return;
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        diff=max(diff,mx-mn);
        check(root->left,mx,mn,diff);
        check(root->right,mx,mn,diff);
    }
};