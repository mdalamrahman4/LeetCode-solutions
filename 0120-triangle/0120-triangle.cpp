class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>&dp) {
        if (i == triangle.size()) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        int left = triangle[i][j] + f(i + 1, j, triangle,dp);
        int right = triangle[i][j] + f(i + 1, j + 1, triangle,dp);
        
        return dp[i][j]=min(left, right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0, 0, triangle,dp);
    }
};