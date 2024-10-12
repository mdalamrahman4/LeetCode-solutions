class Solution {
public:
    int f(int ind,vector<int>&coins,int a,vector<vector<int>>&dp){
        if(ind==0){
            if(a%coins[0]==0)   return a/coins[0];
            return 1e9;
        }
        if(dp[ind][a]!=-1)  return dp[ind][a];
        int take=1e9;
        if(a>=coins[ind])   take=1+f(ind,coins,a-coins[ind],dp);
        int nottake=f(ind-1,coins,a,dp);
        return dp[ind][a]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,coins,amount,dp);
        return (ans==1e9)?-1:ans;
    }
};