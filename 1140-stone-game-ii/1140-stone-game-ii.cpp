class Solution {
public:
    int f(vector<int>piles,bool alice,int ind,int m,vector<vector<vector<int>>>&dp){
        if(ind==piles.size()) return 0;
        if(dp[alice][ind][m]!=-1)   return dp[alice][ind][m];
        int res=(alice?0:1e9),total=0;
        for(int i=1;i<=2*m;i++){
            if(ind+i>piles.size())  break;
            total+=piles[ind+i-1];
            if(alice){
                res=max(res,total+f(piles,!alice,ind+i,max(i,m),dp));
            }
            else{
                res=min(res,f(piles,!alice,ind+i,max(i,m),dp));
            }
        }
        return dp[alice][ind][m]=res;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return f(piles,true,0,1,dp);
    }
};