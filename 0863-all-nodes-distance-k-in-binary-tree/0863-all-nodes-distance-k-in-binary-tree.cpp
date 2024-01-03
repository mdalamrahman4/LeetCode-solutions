/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*> &parenttrack,TreeNode*target)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left)
            {
                parenttrack[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parenttrack[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        mark_parent(root,mp,target);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int lv=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(lv==k) break;
            lv++;
            for(int i=0;i<sz;i++)
            {
                TreeNode*curr=q.front();q.pop();
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if (mp.find(curr) != mp.end() && !vis[mp[curr]])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                }
            }
        }
        vector<int>ans;
            while(!q.empty())
            {
                TreeNode*curr=q.front();
                q.pop();
                ans.push_back(curr->val);
            }
            return ans;
    }
};