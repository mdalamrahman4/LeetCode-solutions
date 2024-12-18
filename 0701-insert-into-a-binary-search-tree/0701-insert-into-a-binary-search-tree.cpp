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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode*curr=root;
        while(true)
        {
            if(curr->val<=val)
            {
                if(curr->right!=NULL)
                {
                    curr=curr->right;
                }
                else
                {
                    TreeNode*ptr=new TreeNode(val);
                    curr->right=ptr;
                    break;
                }
            }
            else
            {
                if(curr->left!=NULL)
                {
                    curr=curr->left;
                }
                else
                {
                    TreeNode*ptr=new TreeNode(val);
                    curr->left=ptr;
                    break;
                }
            }
        }
        return root;
    }
};