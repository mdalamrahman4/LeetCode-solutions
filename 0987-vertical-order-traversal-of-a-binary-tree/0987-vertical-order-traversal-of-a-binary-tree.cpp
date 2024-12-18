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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int col=0;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            TreeNode*node=f.first;
            int x=f.second.first;
            int y=f.second.second;
            mp[x][y].insert(node->val);
            if(node->left)  q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto &c:mp){
            vector<int>col;
            for(auto &r:c.second){
                col.insert(col.end(),r.second.begin(),r.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};