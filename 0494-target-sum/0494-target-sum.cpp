class Solution {
public:
    int f(int ind,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0){
            if(sum==0 && nums[0]==0)    return 2;
            if(sum==0 || sum==nums[0])  return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        int nottake=f(ind-1,sum,nums,dp);
        int take=0;
        if(nums[ind]<=sum){
            take=f(ind-1,sum-nums[ind],nums,dp);
        }
        return dp[ind][sum]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=accumulate(nums.begin(),nums.end(),0);
        if(target>totsum)   return 0;
        if((totsum-target)%2==1)    return 0;
        int sum=(totsum-target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums,dp);
    }
};