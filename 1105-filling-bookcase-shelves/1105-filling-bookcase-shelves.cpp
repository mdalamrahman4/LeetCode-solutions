class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size()+1,0);
        for(int i=1;i<=books.size();i++){
            int height=books[i-1][1];
            int width=books[i-1][0];
            dp[i]=dp[i-1]+height;
            for(int j=i-1;j>0 && width+books[j-1][0]<=shelfWidth;j--){
                height = max(height, books[j-1][1]);
                width += books[j-1][0];
                dp[i] = min(dp[i],dp[j-1] + height);
            }
        }
        return dp[books.size()];
    }
};