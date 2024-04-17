class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        map<int,int>mp;
        for(int i=0;i<points.size();i++){
            mp[points[i][0]]++;
        }
        auto i=mp.begin();
        int prev=i->first;;
        int cnt=1;
        for(auto &it:mp){
            if(it.first-prev>w){
                cnt++;
                prev=it.first;
            }
        }
        return cnt;
    }
};