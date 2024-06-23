class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        double mn=1e9;
        double sum = 0.0;
        int count = 0;
        while (i < j) {
            double mid = (nums[i] + nums[j]) / 2.0;
            if(mid<mn)  mn=mid;
            sum += mid;
            i++;
            j--;
            count++;
        }
        return mn;
    }
};