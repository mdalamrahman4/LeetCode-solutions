class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=0;
        int mx=-1e9,sum=0;
        for(auto &it:nums){
            sum+=it;
            mx=max(mx,sum);
            sum=(sum<0)?0:sum;
        }
        return mx;
    }
};