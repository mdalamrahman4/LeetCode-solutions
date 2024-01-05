class Solution {
public:
    int f(int st, int end, vector<int>& piles, bool turn, vector<vector<int>>& dp) {
        if (st > end) return 0;
        if (dp[st][end] != -1) return dp[st][end];

        if (turn) {
            int s1 = f(st + 1, end, piles, false, dp) + piles[st];
            int s2 = f(st, end - 1, piles, false, dp) + piles[end];
            dp[st][end] = max(s1, s2);
        } else {
            int s1 = f(st + 1, end, piles, true, dp) - piles[st];
            int s2 = f(st, end - 1, piles, true, dp) - piles[end];
            dp[st][end] = min(s1, s2);
        }

        return dp[st][end];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int totalScore = f(0, piles.size() - 1, piles, true, dp);
        return totalScore > 0;  
    }
};
