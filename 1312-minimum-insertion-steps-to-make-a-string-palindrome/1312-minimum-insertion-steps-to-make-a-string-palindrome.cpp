class Solution {
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
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};