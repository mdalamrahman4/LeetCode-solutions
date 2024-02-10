class Solution {
    bool ispalin(string s,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i]!=s[j])  return dp[i][j]=0;
        return dp[i][j] = ispalin(s,i+1,j-1,dp);
    }
public:
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(ispalin(s,i,j,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};