class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        unordered_set<string>st(dict.begin(),dict.end());
        vector<int>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int res=1+dp[ind+1];
            for(int j=ind;j<n;j++){
                string curr=s.substr(ind,j-ind+1);
                if(st.count(curr)){
                    res= min(res,dp[j+1]);
                }
            }
            dp[ind]=res;
        }
        return dp[0];
    }
};