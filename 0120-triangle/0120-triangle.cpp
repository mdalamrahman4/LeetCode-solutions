class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        vector<int>front(m,0),curr(m,0);
        for(int i=0;i<m;i++)    front[i]=triangle[n-1][i];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                curr[j]=triangle[i][j]+min(front[j],front[j+1]);
            }
            front=curr;
        }
        return front[0];
    }
};