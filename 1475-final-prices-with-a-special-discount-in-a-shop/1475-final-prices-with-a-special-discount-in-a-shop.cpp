class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int cost=prices[i];
            int discount=0;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    discount=prices[j];
                    break;
                }
            }
            ans.push_back(cost-discount);
        }
        return ans;
    }
};