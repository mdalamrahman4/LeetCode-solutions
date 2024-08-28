class Solution {
public:
    typedef vector<vector<int>> vv;
    bool check(vv &grid1,vv &grid2,int i,int j){
        int n=grid1.size(),m=grid1[0].size();
        vector<int>row={-1,0,1,0};
        vector<int>col={0,1,0,-1};
        queue<pair<int,int>>q;
        bool result=true;
        grid2[i][j]=-1;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(grid1[x][y]!=1)  result=false;
            for(int i=0;i<4;i++){
                int newx=x+row[i];
                int newy=y+col[i];
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid2[newx][newy]==1){
                    grid2[newx][newy]=-1;
                    q.push({newx,newy});
                }
            }
        }
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