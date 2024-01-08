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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        TreeNode*curr=root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                if(curr->val>=low && curr->val<=high) sum+=curr->val;
                curr=curr->right;
            }
            else{
                TreeNode*prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    if(curr->val>=low && curr->val<=high) sum+=curr->val;
                    curr=curr->right;
                }
            }
        }
        return sum;
    }
};