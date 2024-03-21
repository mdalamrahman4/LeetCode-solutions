class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(auto &it:nums){
            xorr=xorr^it;
        }
        int b1=0,b2=0;
        long long rightmost=(xorr & (xorr-1))^xorr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&rightmost){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};