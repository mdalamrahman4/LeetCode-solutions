class Solution {
public:
    typedef vector<vector<int>> vv;
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vv dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                     dp[i][j]=grid[i][j];
                     continue;
                } 
                int up=(i>0)?dp[i-1][j]:1e9;
                int left=(j>0)?dp[i][j-1]:1e9;
                dp[i][j]=grid[i][j]+min(left,up);
            }
        }
        return dp[n-1][m-1];
    }
};