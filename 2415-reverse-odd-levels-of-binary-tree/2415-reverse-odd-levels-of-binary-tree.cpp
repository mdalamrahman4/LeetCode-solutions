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
    void Reverse(TreeNode* left, TreeNode* right, int level) {
        if (left == NULL || right == NULL)
            return;

        if (level % 2 != 0) {
            swap(left->val, right->val);
        }
        
        Reverse(left->left, right->right, level + 1);
        Reverse(left->right, right->left, level + 1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) 
            return root;
        Reverse(root->left, root->right, 1);
        return root;
    }
};