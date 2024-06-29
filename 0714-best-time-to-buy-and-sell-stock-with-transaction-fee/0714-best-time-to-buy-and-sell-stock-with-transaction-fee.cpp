class Solution {
public:
    int f(int ind,int buy,int fee,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=n)  return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        int profit;
        if(buy==0){
            profit=max(-prices[ind]+f(ind+1,1,fee,n,prices,dp),f(ind+1,0,fee,n,prices,dp));
        }
        else{
            profit=max(-fee+prices[ind]+f(ind+1,0,fee,n,prices,dp),f(ind+1,1,fee,n,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,fee,n,prices,dp);
    }
};