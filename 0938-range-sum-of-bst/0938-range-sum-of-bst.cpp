class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        TreeNode* curr = root;

        while (curr) {
            if (curr->val < low) {
                curr = curr->right;  
            } else if (curr->val > high) {
                curr = curr->left;   
            } else {
                if (curr->left == NULL) {
                    sum += curr->val;
                    curr = curr->right;
                } else {
                    TreeNode* prev = curr->left;
                    while (prev->right && prev->right != curr) {
                        prev = prev->right;
                    }

                    if (prev->right == NULL) {
                        prev->right = curr;
                        curr = curr->left;
                    } else {
                        prev->right = NULL;
                        sum += curr->val;
                        curr = curr->right;
                    }
                }
            }
        }

        return sum;
    }
};
