class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&grid,int n,int m){
        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]<=0 ){
            return 0;
        }
        int curr=grid[row][col];
        grid[row][col]=-grid[row][col];
        int left=dfs(row,col-1,grid,n,m);
        int right=dfs(row,col+1,grid,n,m);
        int up=dfs(row-1,col,grid,n,m);
        int down=dfs(row+1,col,grid,n,m);
        grid[row][col]=-grid[row][col];
        return curr+max(left,max(right,max(up,down)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    sum=max(sum,dfs(i,j,grid,n,m));
                }
            }
        }
        return sum;
    }
};