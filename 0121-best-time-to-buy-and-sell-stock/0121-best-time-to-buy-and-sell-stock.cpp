class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=prices[0];
        int mx=0;
        for(int i=1;i<prices.size();i++){
            mx=max(mx,prices[i]-prev);
            prev=min(prev,prices[i]);
        }
        return mx;
    }
};