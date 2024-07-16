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
    TreeNode*lca(TreeNode*root,int st,int end){
        if(!root)   return NULL;
        if(root->val==st)   return root;
        if(root->val==end)  return root;
        auto l=lca(root->left,st,end);
        auto r=lca(root->right,st,end);
        if(l && r)  return root;
        return l?l:r;
    }
    bool getpath(TreeNode*root,int val,string &path)
    {
        if(!root)   return false;
        if(root->val==val)  return true;
        path+='L';
        auto res=getpath(root->left,val,path);
        if(res) return true;
        path.pop_back();
        path+='R';
        res=getpath(root->right,val,path);
        if(res) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        string p1,p2;
        getpath(root,startValue,p1);
        getpath(root,destValue,p2);
        for(auto &p:p1){
            p='U';
        }
        return p1+p2;
    }
};