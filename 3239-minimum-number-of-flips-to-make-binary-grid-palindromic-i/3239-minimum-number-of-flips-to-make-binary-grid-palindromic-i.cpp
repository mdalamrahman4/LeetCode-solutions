class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rcnt=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            while(low<high){
                if(grid[i][low++]!=grid[i][high--]) rcnt++;
            }
        }
        int ccnt=0;
        for(int i=0;i<m;i++){
            int low=0,high=n-1;
            while(low<high){
                if(grid[low++][i]!=grid[high--][i]) ccnt++;
            }
        }
        return min(ccnt,rcnt);
    }
};