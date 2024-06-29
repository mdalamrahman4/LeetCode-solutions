class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit;
                if(buy==0){
                    profit=max(-prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
                else{
                    profit=max(-fee+prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
            dp[ind][buy]=profit;
            }
        }
        return dp[0][0];
    }
};