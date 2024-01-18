class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int inicolor=image[sr][sc];
        if(color==inicolor) return image;
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+nrow[i];
                    int ny=y+ncol[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==inicolor){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return image;
    }
};