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
    string ans="~";
    void check(TreeNode*root,string str){
        if(!root)   return;
        if(!root->left && !root->right){
            ans=min(ans,char(root->val+'a')+str);
        }
        check(root->left,char(root->val+'a')+str);
        check(root->right,char(root->val+'a')+str);
    }
    string smallestFromLeaf(TreeNode* root) {
        check(root,"");
        return ans;
    }
};