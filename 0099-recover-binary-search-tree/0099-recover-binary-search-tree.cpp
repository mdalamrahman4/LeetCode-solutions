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
    TreeNode*first;
    TreeNode*prev;
    TreeNode*last;
    void inorder(TreeNode*root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev && (root->val<prev->val))
        {
            if(first==NULL)
            {
                first=prev;
                last=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,last->val);
    }
};