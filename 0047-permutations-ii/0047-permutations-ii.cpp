class Solution {
public:
    void check(int ind,vector<vector<int>>&ans,vector<int>nums) {
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) {
            if(i!=ind && nums[ind]==nums[i]) continue;
            swap(nums[ind],nums[i]);
            check(ind+1,ans,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        check(0,ans,nums);
        return ans;
    }
};