class Solution {
    int f(int ind,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(ind==n)  return 0;
        if(dp[ind][buy]!=-1)    return dp[ind][buy];
        int op1,op2;
        if(buy==0){
            op1=f(ind+1,buy,prices,n,dp);
            op2=-prices[ind]+f(ind+1,1,prices,n,dp);
        }
        if(buy==1){
            op1=f(ind+1,buy,prices,n,dp);
            op2=prices[ind]+f(ind+1,0,prices,n,dp);
        }
        return dp[ind][buy]=max(op1,op2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)    return 0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,prices,n,dp);
    }
};