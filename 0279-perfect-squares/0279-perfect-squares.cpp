class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int j=0;j<=n;j++){
            for(int i=1;i*i<=j;i++){
                if(j-i*i>=0) dp[j]=min(dp[j],1+dp[j-i*i]);
            }
        }
        return dp[n];
    }
};