class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>mn(n,1e9),mx(m,-1e9);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mn[i]=min(matrix[i][j],mn[i]);
                mx[j]=max(matrix[i][j],mx[j]);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==mn[i] && matrix[i][j]==mx[j])  ans.push_back(mn[i]);
            }
        }
        return ans;
    }
};