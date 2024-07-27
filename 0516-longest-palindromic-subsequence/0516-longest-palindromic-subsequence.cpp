class Solution {
public:
    int longestPalindromeSubseq(string str) {
        string rev=str;
        reverse(rev.begin(),rev.end());
        int n=str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
        if(str[ind1-1]==rev[ind2-1]){
            dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
        }
        else{
            dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
            }
        }
        return dp[n][n];
    }
};