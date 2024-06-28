class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1,0)),ahead(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=1;cap<=k;cap++){
                    int profit=0;
        if(buy==0){
            profit=max(-prices[ind]+ahead[1][cap],ahead[buy][cap]);
        }
        else{
            profit=max(prices[ind]+ahead[0][cap-1],ahead[buy][cap]);
        }
        curr[buy][cap]=profit;
                }
            }
            ahead=curr;
        }
        return ahead[0][k];
    }
};