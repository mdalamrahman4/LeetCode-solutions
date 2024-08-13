class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        f(0,target,ans,ds,candidates);
        return ans;
    }
    void f(int ind,int target,vector<vector<int>>&ans,vector<int>&ds,vector<int>&candidates){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])   continue;
            if(candidates[i]>target)   break;
            ds.push_back(candidates[i]);
            f(i+1,target-candidates[i],ans,ds,candidates);
            ds.pop_back();
        }
    }
};