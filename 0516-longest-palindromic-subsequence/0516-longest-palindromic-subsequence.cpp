class Solution {
    // int lcs(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j]) return dp[i][j]=1+lcs(i-1,j-1,s1,s2,dp);
    //     else
    //         return dp[i][j]=max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
    // }
public:
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        int n=s2.size();
        vector<int>curr(n+1,0),prev(n+1,0);
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[n];
    }
};