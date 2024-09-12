class Solution {
public:
    int f(int ind,bool buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || cap==2){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1)   return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+f(ind+1,false,cap,prices,dp),f(ind+1,buy,cap,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,true,cap+1,prices,dp),f(ind+1,buy,cap,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,true,0,prices,dp);
    }
};