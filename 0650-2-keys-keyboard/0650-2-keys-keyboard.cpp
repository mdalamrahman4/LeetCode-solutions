class Solution {
public:
    int f(int i,int n,int l,vector<vector<int>>&dp){
        if(i>n) return 1e9;
         else if(!(n-i))
                return 0 ;
				
            else if( dp[i][l] )
                return dp[i][l] ;
				
            else
            {
                int copy  = 2 + f(i+i,n,i,dp); 
                int paste = 1 + f(i+l,n,l,dp);
				
                return dp[i][l] = min( copy, paste );
            }
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        return (n>1?1+f(1,n,1,dp):0);
    }
};