class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        f(0,ans,nums);
        return ans;
    }
    void f(int ind,vector<vector<int>>&ans,vector<int>&nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
};