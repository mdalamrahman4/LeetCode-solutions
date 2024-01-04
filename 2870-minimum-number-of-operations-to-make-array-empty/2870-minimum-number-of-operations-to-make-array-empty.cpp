class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }
        int ans = 0;
        for (auto [key, val] : hash) {
            while (val) {
                if (val == 1) {
                    return -1;
                }
                if (val == 4 || val == 2) {
                    val -= 2;
                    ans++;
                } else {
                    val -= 3;
                    ans++;
                }
            }
        }
        return ans;
    }
};