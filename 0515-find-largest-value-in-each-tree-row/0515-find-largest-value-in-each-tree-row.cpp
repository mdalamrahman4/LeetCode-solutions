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
    vector<int> largestValues(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int mx=INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode*ptr=q.front();
                q.pop();
                mx=max(mx,ptr->val);
                if(ptr->left)   q.push(ptr->left);
                if(ptr->right)  q.push(ptr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};