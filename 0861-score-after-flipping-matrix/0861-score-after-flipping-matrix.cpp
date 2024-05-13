class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){
                    grid[i][j]^=1;
                }
            }
        }
        for(int j=1;j<m;j++){
            int colcnt=0;
            for(int i=0;i<n;i++){
                colcnt+=grid[i][j];
            }
            if(2*colcnt<n){
                for(int i=0;i<n;i++){
                    grid[i][j]^=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=grid[i][j]*1<<(m-j-1);
            }
        }
        return ans;
    }
};