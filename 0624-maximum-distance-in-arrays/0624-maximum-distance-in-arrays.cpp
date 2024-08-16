class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left=arrays[0][0],right=arrays[0].back(),ans=0;
        for(int i=1;i<arrays.size();i++){
            ans=max(ans,max(abs(arrays[i][0]-right),abs(arrays[i].back()-left)));
            left=min(arrays[i][0],left);
            right=max(arrays[i].back(),right);
        }
        return ans;
    }
};