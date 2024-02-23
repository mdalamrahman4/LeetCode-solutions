class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int mn=prices[0];
        for(int i=1;i<prices.size();i++){
            int currprofit=prices[i]-mn;
            maxprofit=max(maxprofit,currprofit);
            mn=min(mn,prices[i]);
        }
        return maxprofit;
    }
};