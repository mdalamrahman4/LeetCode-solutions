class Solution {
public:
    void f(int ind,int sz,vector<int>&ds,vector<vector<int>>&ans,vector<int>&candidates,int target)
    {
        if(ind==sz)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            f(ind,sz,ds,ans,candidates,target-candidates[ind]);
            ds.pop_back();
        }
        f(ind+1,sz,ds,ans,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,candidates.size(),ds,ans,candidates,target);
        return ans;
    }
};