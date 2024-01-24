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
vector<int>dig(10,0);
class Solution {
public:
    int res=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        f(root);
        return res;
    }
    void f(TreeNode*root){
        if(!root) return;
        dig[root->val]++;
        if(!root->left && !root->right){
            int odd=0;
            for(int &a:dig){
                if(a%2==1) odd++;
            }
            if(odd<=1) res++;
        }
        f(root->left);
        f(root->right);
        dig[root->val]--;
     }
};