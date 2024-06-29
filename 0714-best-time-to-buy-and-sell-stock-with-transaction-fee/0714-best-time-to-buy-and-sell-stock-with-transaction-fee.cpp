class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>curr(2,0),ahead(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit;
                if(buy==0){
                    profit=max(-prices[ind]+ahead[1],ahead[0]);
                }
                else{
                    profit=max(-fee+prices[ind]+ahead[0],ahead[1]);
                }
            curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};