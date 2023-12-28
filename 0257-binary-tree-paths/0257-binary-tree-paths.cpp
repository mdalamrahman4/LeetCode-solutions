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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        rec(root,ans,temp);
        return ans;
    }
    void rec(TreeNode*root,vector<string>&ans,string temp)
    {
        if(root==NULL) return;
        if(temp.size()==0) temp+=to_string(root->val);
        else temp+=("->"+to_string(root->val));
        if(!root->left && !root->right) {
            ans.push_back(temp);
            temp="";
        }
        rec(root->left, ans,temp);
        rec(root->right, ans,temp);
    }
};