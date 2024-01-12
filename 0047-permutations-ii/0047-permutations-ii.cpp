class Solution {
public:
    void check(int ind,vector<vector<int>>&ans,vector<int>nums,int sq) {
        if(ind==sq-1){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<sq;i++) {
            if(i!=ind && nums[ind]==nums[i]) continue;
            swap(nums[ind],nums[i]);
            check(ind+1,ans,nums,sq);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        check(0,ans,nums,nums.size());
        return ans;
    }
};
