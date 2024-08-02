class Solution {
public:
    typedef vector<vector<int>> vv;
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>prev(m,0),curr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                     curr[j]=grid[i][j];
                     continue;
                } 
                int up=(i>0)?prev[j]:1e9;
                int left=(j>0)?curr[j-1]:1e9;
                curr[j]=grid[i][j]+min(left,up);
            }
            prev=curr;
        }
        return prev[m-1];
    }
};