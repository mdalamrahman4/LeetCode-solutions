class Solution {
public:
    void sub(int ind,int n,vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        sub(ind+1,n,ans,temp,nums);
        temp.pop_back();
        sub(ind+1,n,ans,temp,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        sub(0,n,ans,temp,nums);
        return ans;
    }
};