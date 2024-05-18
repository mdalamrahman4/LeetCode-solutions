class Solution {
public:
    int res = 0;
    int distributeCoins(TreeNode* root) {
        traversal(root);
        return res;
    }
    int traversal(TreeNode* root)
    {
        if(root->left)
            root->val += traversal(root->left);
        if(root->right)
            root->val += traversal(root->right);
        int temp = root->val -1;
        res += abs(temp);
        return temp;
            
    }
};

