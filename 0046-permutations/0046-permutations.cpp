class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        f(0,ans,nums);
        return ans;
    }
    void f(int n,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(n==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=n;i<nums.size();i++)
        {
            swap(nums[n],nums[i]);
            f(n+1,ans,nums);
            swap(nums[n],nums[i]);
        }
    }
};