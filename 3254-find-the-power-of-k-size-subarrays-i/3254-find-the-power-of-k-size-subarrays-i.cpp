class Solution {
public:
    bool issortedc(vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] != nums[i - 1] + 1) return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)    return nums;
        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            int j = i + k - 1;
            if (issortedc(nums, i, j)) {
                int mx = nums[i];  
                for (int m = i + 1; m <= j; ++m) {
                    mx = max(mx, nums[m]);
                }
                ans.push_back(mx);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
