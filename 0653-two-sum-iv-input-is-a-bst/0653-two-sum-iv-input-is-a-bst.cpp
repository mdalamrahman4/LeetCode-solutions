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
class BstIterator{
    stack<TreeNode*>st;
    bool reverse=true;
    public:
    BstIterator(TreeNode*root,bool reverse)
    {
        this->reverse=reverse;
        pushall(root);
    }
    int next(){
        TreeNode*tmpnode=st.top();
        st.pop();
        if(!reverse) pushall(tmpnode->right);
        else pushall(tmpnode->left);
        return tmpnode->val;
    }
    private:
    void pushall(TreeNode*root)
    {
        for(;root!=NULL;)
        {
            st.push(root);
            if(reverse==true)
                root=root->right;
            else
                root=root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BstIterator l(root,false);
        BstIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};