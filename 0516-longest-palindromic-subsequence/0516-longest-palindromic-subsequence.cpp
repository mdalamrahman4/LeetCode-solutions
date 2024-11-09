class Solution {
public:
    // int lcs(int i,int j,string s,string rev,vector<vector<int>>&dp){
    //     if(i<0 || j<0)  return 0;
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     if(s[i]==rev[j])    return dp[i][j]=1+lcs(i-1,j-1,s,rev,dp);
    //     else{
    //         return dp[i][j]=max(lcs(i-1,j,s,rev,dp),lcs(i,j-1,s,rev,dp));
    //     }
    // }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        int n=s.size();
        vector<int>curr(n+1,0),prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return curr[n];
    }
};