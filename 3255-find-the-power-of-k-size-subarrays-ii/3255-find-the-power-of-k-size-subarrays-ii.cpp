class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)    return nums;
        vector<int> ans(n - k + 1, -1);
        int score = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] + 1 == nums[i])
                score++;
            else
                score = 1;
            if (score >= k )
                ans[i - k + 1] = nums[i];
        }
        return ans;
    }
};