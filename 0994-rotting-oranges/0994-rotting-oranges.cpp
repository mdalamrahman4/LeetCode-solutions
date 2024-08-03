class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0,days=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    cnt++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int k=q.size();
            cnt-=k;
            for(int i=0;i<k;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int adjrow=x+drow[i];
                    int adjcol=y+dcol[i];
                    if(adjrow<0 || adjcol<0 || adjrow>=n || adjcol>=m || grid[adjrow][adjcol]!=1)   continue;
                    grid[adjrow][adjcol]=2;
                    q.push({adjrow,adjcol});
                }
            }
            if(!q.empty())  days++;
        }
        return (cnt!=0)?-1:days;
    }
};