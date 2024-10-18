class Solution {
public:
    int f(int ind,int curror,int xr,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            if(curror==xr)  return 1;
            return 0;
        }
        if(dp[ind][curror]!=-1) return dp[ind][curror];
        int take=f(ind+1,curror|nums[ind],xr,nums,dp);
        int nottake=f(ind+1,curror,xr,nums,dp);
        return dp[ind][curror]=take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int xr=0;
        for(int &it:nums)   xr|=it;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(xr+1,-1));
        return f(0,0,xr,nums,dp);
    }
};