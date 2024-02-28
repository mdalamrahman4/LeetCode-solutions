class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize prefix and suffix arrays with 1s
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        
        // Calculate prefix products
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        
        // Calculate suffix products
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        
        // Calculate final result
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        
        return ans;
    }
};
