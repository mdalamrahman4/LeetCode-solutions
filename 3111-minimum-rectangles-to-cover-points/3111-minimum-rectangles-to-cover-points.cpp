class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int prev=points[0][0];
        int cnt=1;
        for(auto &it:points){
            if(it[0]-prev>w){
                cnt++;
                prev=it[0];
            }
        }
        return cnt;
    }
};