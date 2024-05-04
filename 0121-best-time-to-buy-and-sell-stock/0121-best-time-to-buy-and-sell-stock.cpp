class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mincost=prices[0],maxprofit=0;
        for(auto &it:prices){
            int currprofit=it-mincost;
            maxprofit=max(maxprofit,currprofit);
            mincost=min(mincost,it);
        }
        return maxprofit;
    }
};