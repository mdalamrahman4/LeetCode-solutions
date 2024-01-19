class Solution {
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis,int delrow[],int delcol[]){
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        for(int x=0;x<4;x++){
            int nrow=i+delrow[x];
            int ncol=j+delcol[x];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && board[i][j]=='O'){
                dfs(nrow,ncol,board,vis,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,vis,delrow,delcol);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,board,vis,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis,delrow,delcol);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    vis[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
    }
};