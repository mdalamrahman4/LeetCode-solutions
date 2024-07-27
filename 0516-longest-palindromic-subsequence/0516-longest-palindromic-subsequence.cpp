class Solution {
public:
    int longestPalindromeSubseq(string str) {
        string rev=str;
        reverse(rev.begin(),rev.end());
        int n=str.size();
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
        if(str[ind1-1]==rev[ind2-1]){
            curr[ind2]=1+prev[ind2-1];
        }
        else{
            curr[ind2]=max(prev[ind2],curr[ind2-1]);
        }
            }
            prev=curr;
        }
        return prev[n];
    }
};