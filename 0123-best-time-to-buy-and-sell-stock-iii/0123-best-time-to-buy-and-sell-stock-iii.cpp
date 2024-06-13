class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit;
                    if(buy==1){
                            profit=max(dp[ind+1][buy][cap],-prices[ind]+dp[ind+1][0][cap]);
        }
        else{
            profit=max(dp[ind+1][buy][cap],prices[ind]+dp[ind+1][1][cap-1]);
        }
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};