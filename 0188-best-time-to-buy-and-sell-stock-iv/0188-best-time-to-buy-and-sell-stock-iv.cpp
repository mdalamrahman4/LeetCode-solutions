class Solution {
public:
    int f(int ind,int n,int buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==n || k==0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        int profit=0;
        if(buy==0){
            profit=max(
                -prices[ind]+f(ind+1,n,1,k,prices,dp),
                f(ind+1,n,buy,k,prices,dp)
            );
        }
        else{
            profit=max(
                prices[ind]+f(ind+1,n,0,k-1,prices,dp),
                f(ind+1,n,buy,k,prices,dp)
            );
        }
        return dp[ind][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,n,0,k,prices,dp);
    }
};