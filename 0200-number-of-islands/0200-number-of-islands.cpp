class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid);
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    vis[i][j]=1;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
void Solution:: bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
            queue<pair<int,int>>q;
            int n=grid.size(),m=grid[0].size();
            q.push({row,col});
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=x+delrow[i];
                    int ncol=y+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 &&
                      grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
      }