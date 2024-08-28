class Solution {
public:
    typedef vector<vector<int>> vv;
    bool check(vv &grid1,vv &grid2,int i,int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid2[0].size()){
            return true;
        }
        if(grid2[i][j]!=1)   return true;
        grid2[i][j]=-1;
        bool result=(grid1[i][j]==1);
        result=result & check(grid1,grid2,i-1,j);
        result=result & check(grid1,grid2,i+1,j);
        result=result & check(grid1,grid2,i,j-1);
        result=result & check(grid1,grid2,i,j+1);
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subislands=0,n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && check(grid1,grid2,i,j)){
                    subislands++;
                }
            }
        }
        return subislands;
    }
};