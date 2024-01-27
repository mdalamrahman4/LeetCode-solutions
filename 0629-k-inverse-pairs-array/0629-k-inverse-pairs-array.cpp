class Solution {
public:
    int kInversePairs(int N, int K) {
        int dp[1001][1001] = {1};
        for(int i = 1;i<=N;i++)
        {
            for(int j=0;j<=K;j++)
            {
                for(int k=0;k<= min(j,i-1);k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k])%1000000007;
                }
            }
        }
        return dp[N][K];
    }
};