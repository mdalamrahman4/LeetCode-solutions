class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,mx=INT_MIN;
        for(auto &it:nums){
            sum+=it;
            mx=max(mx,sum);
            sum=(sum<0)?0:sum;
        }
        return mx;
    }
};