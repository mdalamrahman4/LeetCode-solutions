class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int days=0,tot=0,cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    tot++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1 ) continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }
        return ((tot==cnt)?days:-1);
    }
};