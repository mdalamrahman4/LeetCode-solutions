class Solution {
public:
    int f(int ind,bool buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || cap==2){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1)   return dp[ind][buy][cap];
        int profit;
        if(buy){
            profit=max(f(ind+1,buy,cap,prices,dp),-prices[ind]+f(ind+1,false,cap,prices,dp));
        }
        else{
            profit=max(f(ind+1,buy,cap,prices,dp),prices[ind]+f(ind+1,true,cap+1,prices,dp));
        }
        dp[ind][buy][cap]=profit;
        return dp[ind][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,true,0,prices,dp);
    }
};