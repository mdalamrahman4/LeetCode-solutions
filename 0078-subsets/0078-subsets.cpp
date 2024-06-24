class Solution {
public:
    void tryall(int ind,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        tryall(ind+1,n,nums,temp,ans);
        temp.pop_back();
        tryall(ind+1,n,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        tryall(0,n,nums,temp,ans);
        return ans;
    }
};