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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size(),sum=0;
            vector<TreeNode*>v;
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                v.push_back(node);
                if(node->left)  {
                    sum+=node->left->val;
                    q.push(node->left);
                }
                if(node->right) {
                    sum+=node->right->val;
                    q.push(node->right);
                }
            }
            for(auto it:v){
                int curr=sum;
                if(it->left)    curr-=it->left->val;
                if(it->right)   curr-=it->right->val;
                if(it->left)    it->left->val=curr;
                if(it->right)   it->right->val=curr;
            }
        }
        return root;
    }
};