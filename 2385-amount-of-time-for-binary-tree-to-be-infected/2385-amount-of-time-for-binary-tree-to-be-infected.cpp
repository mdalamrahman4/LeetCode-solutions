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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode*target=mapparent(root,mp,start);
        int maxim=fmd(mp,target);
        return maxim;
    }
    TreeNode*mapparent(TreeNode*root,map<TreeNode*,TreeNode*>&mp,int start)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*res;
        while(!q.empty())
        {
            TreeNode*node=q.front();
            if(node->val==start) res=node;
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            } 
            if(node->right)
            {
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int fmd(map<TreeNode*,TreeNode*>&mp,TreeNode*target)
    {
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,int>vis;
        vis[target]=1;
        int maxi=0;
        while(!q.empty())
        {
            int sz=q.size();
            int f1=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    f1=1;
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right])
                {
                    f1=1;
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(mp[node] && !vis[mp[node]])
                {
                    f1=1;
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                }
            }
            if(f1) maxi++;
        }
        return maxi;
    }
};