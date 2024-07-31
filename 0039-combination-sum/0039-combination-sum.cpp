typedef vector<vector<int>> vv;
typedef vector<int> v;
class Solution {
public:
    void f(int ind,int n,v &ds,vv &ans, v &candidates, int target){
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            f(ind,n,ds,ans,candidates,target-candidates[ind]);
            ds.pop_back();
        }
        f(ind+1,n,ds,ans,candidates,target);
    }
    vv combinationSum(v & candidates, int target) {
        vv ans;
        v ds;
        f(0,candidates.size(),ds,ans,candidates,target);
        return ans;
    }
};