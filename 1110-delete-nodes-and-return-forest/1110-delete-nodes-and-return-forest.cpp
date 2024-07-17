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
    unordered_set<int>s;
    vector<TreeNode*>ans;
    TreeNode*dfs(TreeNode*root){
        if(!root)   return NULL;
        root->left=dfs(root->left);
        root->right=dfs(root->right);
        if(s.count(root->val)){
            if(root->left)  ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s = unordered_set<int>(to_delete.begin(), to_delete.end());
        if(!s.count(root->val)){
            ans.push_back(root);
        }
        dfs(root);
        return ans;
    }
};