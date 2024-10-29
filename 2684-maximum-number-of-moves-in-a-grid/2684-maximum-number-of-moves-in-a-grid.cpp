class Solution {
public:
    vector<int>directions={-1,0,1};
    int dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int move=0;
        for(auto &it:directions){
            int nrow=row+it;
            int ncol=col+1;
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[row][col]<grid[nrow][ncol]){
                move=max(move,1+dfs(nrow,ncol,grid,dp));
            }
        }
        return dp[row][col]=move;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int row=0;row<n;row++){
            ans=max(ans,dfs(row,0,grid,dp));
        }
        return ans;
    }
};