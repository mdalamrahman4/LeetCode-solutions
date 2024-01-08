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
    int sumNumbers(TreeNode* root) {
        TreeNode*curr=root;
        int totsum=0,currsum=0,depth=0;
        while(curr)
        {
            if(curr->left==NULL)
            {
                currsum=currsum*10+curr->val;
                if(curr->right==NULL) {totsum+=currsum;}
                curr=curr->right;
            }
            else{
                TreeNode*prev=curr->left;
                depth=1;
                while(prev->right && prev->right!=curr){ prev=prev->right,depth++;}
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    currsum=currsum*10+curr->val;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    if(prev->left==NULL ) totsum+=currsum;
                    currsum=currsum/pow(10,depth);
                    curr=curr->right;
                }
            }
        }
            return totsum;
    }
};