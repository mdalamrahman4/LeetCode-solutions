class Solution {
public:
    typedef vector<vector<int>> vv;
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vv dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)   dp[0][i]=1e9;
        for(int i=1;i<=n;i++)   dp[i][0]=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1){
                     dp[i][j]=grid[i-1][j-1];
                     continue;
                } 
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=grid[i-1][j-1]+min(left,up);
            }
        }
        return dp[n][m];
    }
};