class Solution {
public:
    typedef vector<vector<int>> vv;
    int f(int i,int j,vv &grid,vv &dp){
        if(i==0 && j==0)    return grid[0][0];
        if(i<0 || j<0)  return 1e9;
        if(dp[i][j]!=-1)    return dp[i][j];
        int up=f(i-1,j,grid,dp);
        int left=f(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vv dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};